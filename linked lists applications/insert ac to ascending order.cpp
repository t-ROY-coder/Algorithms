#include<iostream>
using namespace std;
struct node
{
	int data;
	node *next;
};
node *a,*b,*c;
int main()
{
	int x;
	cout<<"enter the values and press -1 to stop";
	cin>>x;
	a=new node;
	a->data=x;
	a->next=NULL;
	c=a;
	b=a;
	cin>>x;
	while(x!=-1)
	{
		node *temp;
		temp=new node;
		temp->data=x;
		temp->next=NULL;
		a->next=temp;
		a=a->next;
		cin>>x;
	}
	cout<<"enter the value you want to insert";
	cin>>x;
	if(b->data>x)
	{
		node *temp;
		temp=new node;
		temp->data=x;
		temp->next=NULL;
		temp->next=b;
		c=temp;
	}
	else
	{
	while((b->next->data<x))
	{
		b=b->next;
		if(b->next==NULL)
		break;
	}
	node *temp;
	temp=new node;
	temp->data=x;
	temp->next=NULL;
	temp->next=b->next;
	b->next=temp;
    }
	while(c!=NULL)
	{
		cout<<c->data;
		c=c->next;
	}
	return 0;
}
