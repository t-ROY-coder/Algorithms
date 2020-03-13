#include<iostream>
#include<cmath>
using namespace std;
struct node
{
	int data;
	node *left,*right;
};
node *root=NULL;
int h,f=-1,r=-1;
node *a[20],*temp;
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
void push(struct node*g)
{
	r++;
	a[r]=g;
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
	h=height(root);
	int w;
	w=pow(2,h)-1;
	f++;
	r++;
	a[r]=root;
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
	display(root);
	return 0;
}
