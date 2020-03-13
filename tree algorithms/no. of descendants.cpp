#include<iostream>
using namespace std;
struct node
{
	int data;
	node *left,*right;
};
int a[100],z=0,count=0;
node *root=NULL;
//struct create(struct node *t,int n);
struct node*create(struct node *t,int n)
{
	if(t==NULL)
	{
		node *temp;
		temp=new node;
		temp->data=n;
		temp->left=NULL;
		temp->right=NULL;
		t=temp;
	}
	else
	{
	 if(n<t->data)
	 t->left=create(t->left,n);
	 if(n>t->data)
	 t->right=create(t->right,n);
	}
	return t;
}
void height(struct node*t)
{
	
	if(t->left!=NULL)
	{
	count++;
	height(t->left);
    }
	if(t->right!=NULL)
	{
	count++;
	height(t->right);
    }
}
void display(struct node*t)
{
	if(t==NULL)
	return;
	count=0;
	height(t);
	cout<<"no. of descendants for node "<<t->data<<"is "<<count<<"\n";
	display(t->left);
	display(t->right);	
}
int main()
{
	int n;
	cout<<"enter no.";
	cin>>n;
	while(n>0)
	{
		root=create(root,n);
		cout<<"enter no.";
		cin>>n;
	}
	display(root);
	return 0;
}
