#include<iostream>
using namespace std;
struct node
{
	int data;
	node *left,*right;
};
int a[100],z=0;
struct node1
{
	int position,value,level;
	node1 *next;
};
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
node1 *q=NULL;
node1 *start,*b,*c;
void push(int i,int n,int l)
{
	if(q==NULL)
	{
		q=new node1;
		q->position=i;
		q->value=n;
		q->level=l;
		q->next=NULL;
		start=q;
		b=q;
		c=q;
	}
	else
	{
		node1 *temp;
		temp=new node1;
		temp->position=i;
		temp->value=n;
		temp->level=l;
		temp->next=NULL;
		q->next=temp;
		q=q->next;
	}
}
void sort()
{
	while(c!=NULL)
	{
		b=c->next;
	    while(b!=NULL)
		{
			if(c->level>b->level)
			{
				int q=c->level;
				c->level=b->level;
				b->level=q;
				int q1=c->position;
				c->position=b->position;
				b->position=q1;
				int q2=c->value;
				c->value=b->value;
				b->value=q2;
			}
			b=b->next;
		}
		c=c->next;
	}
}
void height(int i,struct node*t,int j)
{
	if(t->left!=NULL)
	{
	push(i-1,t->left->data,j+1);
	height(i-1,t->left,j+1);
   }
   if(t->right!=NULL)
   {
   	push(i+1,t->right->data,j+1);
   	height(i+1,t->right,j+1);
   }
}
void display()
{
	while(start!=NULL)
	{
	    int x=0;
		for(int y=0;y<z;y++)
		{
			if(a[y]==start->position)
			x++;
		}
		if(x==0)
		cout<<start->value<<" ";//<<start->position<<" "<<start->level<<endl;
		a[z]=start->position;
		z++;
		x=0;
		start=start->next;
	}
}
int main()
{
	node *root=NULL;
	int n;
	cout<<"enter no.";
	cin>>n;
	while(n>0)
	{
		root=create(root,n);
		cout<<"enter no.";
		cin>>n;
	}
	push(0,root->data,1);
	height(0,root,1);
	sort();
	//cout<<root->data<<" ";
	display();
	return 0;
}
