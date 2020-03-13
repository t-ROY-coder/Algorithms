#include<iostream>
using namespace std;
struct node
{
	int data;
	node *left,*right;
};
node *root=NULL;
//struct create(struct node *t,int n);
void min()
{
	node *t=root;
	while(t->left!=NULL)
	t=t->left;
	cout<<"the minimum element is"<<t->data;
}
void max()
{
	node *t=root;
	while(t->right!=NULL)
	t=t->right;
	cout<<"the maximum element is"<<t->data;
}
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
	cout<<t->data<<"\n";
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
	cout<<endl;
	min();
	cout<<endl;
	max();
	return 0;
}
