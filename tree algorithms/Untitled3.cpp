#include<iostream>
#include<cmath>
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
node *a[20];
int f=-1,r=-1,h;
struct node*create(struct node*t,struct node1*order)
{
	node *temp=new node;
	temp->data=pre->data1;
	temp->left=NULL;
	temp->right=NULL;
	t=temp;
	node1 *temp1=order;
	while(order->data1!=pre->data1 && order->next!=NULL)
	order=order->next;
    node1 *g=order->next;
    node1 *p=order->previous;
    order=NULL;
    if(temp1!=NULL && pre->next!=NULL)
	{
	pre=pre->next;
	t->left=create(t->left,temp1);
	}
    if(g!=NULL && pre->next!=NULL)
	{
	pre=pre->next;
	t->right=create(t->right,g);
	}
	return t;
}
void push(struct node*p)
{
	r++;
	a[r]=p;
}
int height(struct node*t)
{
	int lh,rh;
	if (t==NULL)
	return 0;
	else
	{
		lh=height(t->left);
		rh=height(t->right);
	}
	if(lh>rh)
	return (1+lh);
	else
	return (1+rh);
}
void display(struct node*t);
void display(struct node*t)
{
	h=height(root);
	int w;
	w=pow(2,h)-1;
	f++;
	r++;
	a[r]=root;
	node *temp;
	temp=new node;
	temp->data=-1;
	temp->right=NULL;
	temp->left=NULL;
	while(r!=w-1)
	{
		if(a[f]->left!=NULL)
		push(a[f]->left);
		if(a[f]->left==NULL)
		push(temp);
		if(a[f]->right!=NULL)
		push(a[f]->right);
		if(a[f]->right==NULL)
		push(temp);
		f++;
	}
	int j=0;
	f=0;
	r=0;
	 for(int k=0;k<h;k++)
	 {
	 //	cout<<endl;
	 	cout<<endl;
     for(int i=0;i<pow(2,h-k-1)-1;i++)
      cout<<" ";
      for(int l=0;l<pow(2,k);l++)
      {
      if(a[f]->data!=temp->data)
      cout<<a[f]->data;
      else
      cout<<" ";
      for(int y=0;y<pow(2,h-k)-1;y++)
      cout<<" ";
      f++;
      }  
     }
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
