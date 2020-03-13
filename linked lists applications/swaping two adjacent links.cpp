#include<iostream>
using namespace std;
struct node
{
	int data;
	node *next;
};
node *a,*b,*c,*d;
int i=0;
void swap();
void swap()
{
	node *temp,*temp1;
	if(i==0)//for first two elements
	{
		temp=b->next;
		b->next=temp->next;
		temp->next=b;
		i++;
		d=temp;
	}
	else if(b->next->next->next==NULL)//for last element
	{
		temp=b->next;
		temp1=temp->next;
		b->next=temp1;
		temp1->next=temp;
		temp->next=NULL;
		b=b->next;
		
	}
	else//for middle elements
	{
		temp=b->next;
		temp1=temp->next;
		temp->next=temp1->next;
		temp1->next=temp;
		b->next=temp1;
		b=b->next->next;
	}
}
int main()
{
	int n;
	cout<<"enter the values and press -1 to stop";
	cin>>n;
	a=new node;
	a->data=n;
	a->next=NULL;
	b=a;
	c=a;
	d=a;
	cin>>n;
	while(n>0)
	{
	    node *temp;
	    temp=new node;
	    temp->data=n;
	    temp->next=NULL;
	    a->next=temp;
	    a=a->next;
	    cin>>n;
	}
	while(b->next!=NULL && b->next->next!=NULL)
	{
		swap();
		//cout<<"a";
	}
	while(d!=NULL)
	{
		cout<<d->data;
		d=d->next;
	}
	return 0;
}
