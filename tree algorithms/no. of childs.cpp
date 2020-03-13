#include<iostream>
using namespace std;
struct node
{
	int data;
	node *left,*right;
};
int a=0,b=0,c=0;
node *root=NULL;
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
void child(struct node*t)
{
	if(t->left==NULL && t->right==NULL)
	a++;
	else if(t->left==NULL || t->right==NULL)
	b++;
	else
	c++;
	if(t->right!=NULL)
	child(t->right);
	if(t->left!=NULL)
	child(t->left);
}
int main()
{
	int n;
	cout<<"enter the values of tree and press -1 to stop";
	cin>>n;
	while(n!=-1)
	{
		root=create(root,n);
		cin>>n;
	}
	child(root);
	cout<<"no. of nodes with two children: "<<c;
	cout<<"\n no. of nodes with one child: "<<b;
	cout<<"\n no. of nodes with no child: "<<a;
}
