#include<iostream>
#include<cmath>
using namespace std;
struct node
{
	int data;
	int factor;
	node *left,*right;
};
node *root=NULL;
int n,h,f=-1,r=-1,qw=0,f1=-1,r1=-1;
node *a[20],*temp,*b[20];
struct node*create(struct node*t,int n)
{
	if(t==NULL)
	{
		node *temp;
		temp=new node;
		temp->data=n;
		temp->factor=0;
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
	if(t==NULL)
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
struct node*parent(struct node*b)
{
	node *m=root;
	while(m!=b && m->left!=b && m->right!=b)
	{
		if(b->data>m->data)
		m=m->right;
		else
		m=m->left;
	}
	return m;

}
void singlerotateleft(struct node*t)
{
    	node *p=parent(t);
    	node *p1=parent(p);
    	p->left=t->right;
		t->right=p;
		if(root->data==p->data)
		root=t;
	    else if(p1->data>t->data)
	    p1->left=t;
	    else
	    p1->right=t;
		
}
void singlerotateright(struct node*t)
{
	node *p=parent(t);
	node *p1=parent(p);
	p->right=t->left;
	t->left=p;
	if(root->data==p->data)
	root=t;
	else if(p1->data>t->data)
	p1->left=t;
	else
	p1->right=t;
}
void doublerotateleft(struct node*t)
{
	singlerotateright(t);
	singlerotateleft(t);
}
void doublerotateright(struct node*t)
{
	singlerotateleft(t);
	singlerotateright(t);
}
void push1(struct node*t)
{
	f1=0;
	r1++;
	b[r1]=t;
}
void process1(struct node*t)
{
	int z=height(t->left);
	int x=height(t->right);
				if(z>x)
			{
				if(height(t->left->left)<height(t->left->right))
				doublerotateleft(t->left->right);
				else
				singlerotateleft(t->left);
			}
			else
			{
				if(height(t->right->left)>height(t->right->right))
				doublerotateright(t->right->left);
				else
				singlerotateright(t->right);
			}
}
void process(struct node*t)
{
	qw=0;
	int z=height(t->left);
	int x=height(t->right);
	t->factor=z-x;
   	 if(t->factor!=1 && t->factor!=0 && t->factor!=-1)
	 {
     qw++;
	 push1(t);
	 }
	if(t->left!=NULL)
	process(t->left);
	if(t->right!=NULL)
	process(t->right);
}
void push(struct node*p)
{
	r++;
	a[r]=p;
}
void display(struct node*t);
void display(struct node*t)
{
	int j=0;
	f=0;
	r=0;
	 for(int k=0;k<h;k++)
	 {
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
int main()
{
	cout<<"enter the values you want to insert and press -1 to stop";
	cin>>n;
	while(n!=-1)
	{
		root=create(root,n);
		do
		{
		process(root);
		if(r1!=-1)
		process1(b[r1]);
		f1=-1;
		r1=-1;
	    }while(qw!=0);
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
}
