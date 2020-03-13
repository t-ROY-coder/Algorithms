#include<iostream>
using namespace std;
struct node
{
	int data;
	node *left,*right;
};
node *root=NULL;
node *stack1[20],*stack2[20];
int top1=-1,top2=-1;
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
void push1(struct node*p)
{
	top1++;
	stack1[top1]=p;
}
void push2(struct node*p)
{
	top2++;
	stack2[top2]=p;
}
void display(struct node*t);
void display(struct node*t)
{
	do
	{
		node *p;
		p=stack1[top1];
		top1--;
		push2(p);
		if(p->left!=NULL)
		push1(p->left);
		if(p->right!=NULL)
		push1(p->right);
	}while(top1!=-1);
	while(top2!=-1)
	{
		cout<<stack2[top2]->data<<" ";
		top2--;
	}
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
	top1++;
	stack1[top1]=root;
	display(root);
	return 0;
}
