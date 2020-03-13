#include<iostream>
using namespace std;
struct node
{
	int data;
	node *next;
};
node *a,*c,*b,*d;
int i=0,j,k;
void sort();
void sort()
{
	while(c->next!=NULL)
	{
		b=d;
	    while(b->next!=NULL)
		{
			if(b->data>b->next->data)
			{
				int q=b->data;
				b->data=b->next->data;
				b->next->data=q;
			}
			b=b->next;
		}
		c=c->next;
		//sort();
	}
}
void display();
void display()
{
	while(d!=NULL)
	{
		cout<<"\n"<<d->data;
		d=d->next;
	}
}
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
	d=a;
	i++;
	cin>>x;
	while(x!=-1)
	{
		node *temp;
		temp=new node;
		temp->data=x;
		temp->next=NULL;
		a->next=temp;
		a=a->next;
		i++;
		cin>>x;
	}
	sort();
	display();
	return 0;
}
	


