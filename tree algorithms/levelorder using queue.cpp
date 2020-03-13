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
	int h=0;
	node *temp;
	temp=new node;
	temp->data=-1;
	temp->left=NULL;
	temp->right=NULL;
	push(temp);
	h++;
	while(f!=r+1)
	{
				if(a[f]->data==temp->data)
		{
			push(temp);
			h++;
			f++;
			cout<<endl;
		}
		if(h!=1)
		if((a[f]->data==temp->data)&&(a[f-1]->data==temp->data))
		break;
		cout<<a[f]->data<<" ";
		if(a[f]->left!=NULL)
		push(a[f]->left);
		if(a[f]->right!=NULL)
		push(a[f]->right);
		f++;
	}
	cout<<"height of tree is ";
	cout<<h-1;
	return 0;
}
