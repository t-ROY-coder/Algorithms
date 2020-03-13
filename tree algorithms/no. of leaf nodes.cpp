#include<iostream>
using namespace std;
struct node
{
	int data;
	node *left,*right;
};
int a[100],z=0;
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
void height(int i,struct node*t);
void height(int i,struct node*t)
{
	if(t->left!=NULL ||t->right!=NULL)
	i++;
	else 
	{
		a[z]=i;
		z++;
	}
	if(t->left!=NULL)
	height(i,t->left);
	if(t->right!=NULL)
	height(i,t->right);
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
	height(0,root);
	cout<<z;
	return 0;
}
