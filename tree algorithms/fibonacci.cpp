#include<iostream>
using namespace std;
struct node
{
	int data;
	node *left,*right;
};
int o,a[20],k=0,f=-1,r=-1;
node *c[20];
node *root=NULL;
void fibonaci(int ord)
{
	a[k]=1;
	k++;
	a[k]=1;
    while(a[k]!=ord)
	{
		k++;
		a[k]=a[k-1]+a[k-2];
	}
}
int find(int q)
{
	int z=0;
	while(a[z]!=q)
	{
		z++;
	}
	return z;
}
struct node*create(struct node*t,int order)
{
	
	
	if(t==NULL)
	{
		node *temp;
		temp=new node;
		temp->data=a[order];
		temp->left=NULL;
		temp->right=NULL;
		t=temp;
	}
	if(order>=2)
	{
		t->left=create(t->left,order-1);
		t->right=create(t->right,order-2);
	}
	return t;
   
}
void push(struct node*p)
{
	r++;
	c[r]=p;
}
void display()
{
		f++;
	r++;
	c[r]=root;
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
		if(c[f]->data==temp->data)
		{
			push(temp);
			h++;
			f++;
			cout<<endl;
		}
		if(h!=1)
		if((c[f]->data==temp->data)&&(c[f-1]->data==temp->data))
		break;
		cout<<c[f]->data<<" ";
		if(c[f]->left!=NULL)
		push(c[f]->left);
		if(c[f]->right!=NULL)
		push(c[f]->right);
		f++;
	}
}
/*void display(struct node*t)
{
	if(t==NULL)
	return;
	cout<<t->data<<"\n";
	display(t->left);
	display(t->right);
}*/
int main()
{
	int order;
	cout<<"enter the order of tree";
	cin>>o;
	fibonaci(o);
	order=find(o);
	root=create(root,order);
	display();
}
