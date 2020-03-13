#include<iostream>
using namespace std;
struct node
{
	int data;
	node *left,*right;
};
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
void display(struct node*t);
void display(struct node*t)
{
	if(t==NULL)
	return;
	cout<<t->data<<"  "<<&t<<"\n";
	display(t->left);
	display(t->right);
}
struct node*find(struct node*t,int n)
{
	if(t==NULL)
	return NULL;
	else
	{
		if(t->data==n)
		return t;
		else if(t->data>n)
		find(t->left,n);
		else if(t->data<n)
		find(t->right,n);
	}
    // return t;	
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
	cout<<"enter the element you want to search";
	cin>>n;
	node *p=find(root,n);
	cout<<&p;
	return 0;
}
