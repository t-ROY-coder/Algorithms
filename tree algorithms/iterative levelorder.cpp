#include<iostream>
using namespace std;
struct node
{
	int data;
	node *left,*right;
};
node *root=NULL;
node *a[20];
int f=-1,r=-1;
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
void push(struct node*p)
{
	r++;
	a[r]=p;
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
	f++;
	r++;
	a[r]=root;
	while(f!=r+1)
	{
		cout<<a[f]->data;
		if(a[f]->left!=NULL)
		push(a[f]->left);
		if(a[f]->right!=NULL)
		push(a[f]->right);
		f++;
	}
	return 0;
}
