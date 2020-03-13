#include<iostream>
using namespace std;
struct node
{
	int data;
	node *left,*right;
};
struct node1
{
	int data1;
	node1 *next,*previous;
};
node *root=NULL;
node1 *b,*c,*start1,*start2,*pre,*in;
struct node1*divide(struct node1*order)
{
	cout<<"order";
	node1 *temp=order;
	cout<<"find";
	if(temp==NULL)
	cout<<"qwerrt";
	cout<<temp->data1;
	while(temp->data1!=pre->data1 && temp!=NULL)
	temp=temp->next;
	cout<<"order4";
    node1 *g=temp->next;
    cout<<"order5";
    node1 *p=temp->previous;
    cout<<"order6";
    g->previous=NULL;
    cout<<"order7";
	p->next=NULL;
	cout<<"order8";
	cout<<"\n";
	return order,g;
	
}
struct node*create(struct node*t,struct node1*order)
{
	node *temp=new node;
	temp->data=pre->data1;
	temp->left=NULL;
	temp->right=NULL;
	t=temp;
	node1 *order1,*order2=divide(order);
	if(order1!=NULL && pre->next!=NULL)
	{
	cout<<"order1";
	pre=pre->next;
	t->left=create(t->left,order1);
	cout<<"order3";
	}
	if(order2!=NULL && pre->next!=NULL)
	{
	cout<<"order2";
	pre=pre->next;
	t->right=create(t->right,order2);
	}
	return t;
}
void display(struct node*t)
{
	if(t==NULL)
	return;
	cout<<t->data<<"\n";
	display(t->left);
	display(t->right);
}
int main()
{
	int n;
	cout<<"enter the pre order traversal and press -1 after completing";
	cin>>n;
		b=new node1;
		b->data1=n;
		b->next=NULL;
		b->previous=NULL;
		start1=b;
		pre=b;
		cin>>n;
	while(n!=-1)
	{
	   node1 *temp;
	   temp=new node1;
	   temp->data1=n;
	   temp->next=NULL;
	   temp->previous=NULL;
	   b->next=temp;
	   temp->previous=b;
	   b=b->next;
	   cin>>n;
	}
	cout<<"enter the inorder traversal and press -1 after completing";
	cin>>n;
	c=new node1;
	c->data1=n;
	c->next=NULL;
	c->previous=NULL;
	start2=c;
	in=c;
	cin>>n;
	while(n!=-1)
	{
		node1 *temp;
	   temp=new node1;
	   temp->data1=n;
	   temp->next=NULL;
	   temp->previous=NULL;
	   c->next=temp;
	   temp->previous=c;
	   c=c->next;
	   cin>>n;
	}
	root=create(root,in);
	display(root);
}
