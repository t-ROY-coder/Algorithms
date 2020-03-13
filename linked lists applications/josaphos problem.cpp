#include<iostream>
using namespace std;
struct node
{
	int data;
	node *next;
};
node *a,*b,*start;
int n,p;
void delet();
void delet()
{
	a=start;
	while(a->data!=a->next->data)
	{
		for(int k=0;k<p-1;k++)
		a=a->next;
		node *c;
		c=a->next;
		a->next=c->next;
		delete c;
		a=a->next;
	}
	if((a->data==a->next->data)&&(p!=0))
	cout<<"the position of winner is"<<a->data;
	
}
int main()
{
	a=new node;
	cout<<"enter the no. of participants";
	cin>>n;
	a->data=1;
	a->next=NULL;
	start=a;
	int i=1;
	while(i<n)
	{
		node *temp;
		temp=new node;
		temp->data=i+1;
		temp->next=NULL;
		a->next=temp;
		a=a->next;
		i++;
		
	}
	a->next=start;
	cout<<"enter the no. of passes";
	cin>>p;
	if(p==0)
	cout<<"the winner position is"<<i;
	delet();
}
