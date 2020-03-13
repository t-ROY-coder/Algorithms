#include<iostream>
using namespace std;
struct node
{
	int data;
	node *next;
};
int main()
{
	node *a,*b,*c,*e,*f,*g;
	int i,j,d=0,x,h=0;
	a=new node;
	b=new node;
	cout<<"enter the elements of 1st linked list and press -1 to stop";
	cin>>x;
	a->data=x;
	c=a;
	f=a;
	cin>>x;
	while(x!=-1)
	{
		node *t;
		t=new node;
		t->data=x;
		t->next=NULL;
		a->next=t;
		a=a->next;
		cin>>x;
	}
	cout<<"enter the elements of 2nd linked list and press -1 to stop";
	cin>>x;
	b->data=x;
	e=b;
	cin>>x;
	while(x!=-1)
	{
		node *t;
		t=new node;
		t->data=x;
		t->next=NULL;
		b->next=t;
		b=b->next;
		cin>>x;
		
	}
	a->next=e;
	cout<<"catenated list is";
	while(c!=NULL)
	{
		cout<<c->data;
		c=c->next;
	}
	return 0;
}
