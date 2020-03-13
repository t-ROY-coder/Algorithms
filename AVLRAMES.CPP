#include<iostream.h>
struct node
{
	struct node *lchild;
	struct node *rchild;
	int data;
};
typedef struct node *avl;
int max(int a,int b)
{
	if(a>b) return a;
	if(a<b) return b;
}
int h(avl t)
{
	if(t==NULL)  return -1;
	else return(max(h(t->lchild),h(t->rchild)));
}
int correct(avl t)
{
	k=h(t->lchild)-h(t->rchild);
	if((k>-1)&&(k<1)) return 1;
	else return 0;
}
void single(avl &t,int x)
{
	avl p,n;
	p=t;
	n=t;
	while(p->data!=x)
	{
		if(x<p->data) p=p->lchild;
		else p=p->rchild;
	}
	while(n->lchild->data!=x|n->rchild->data!=x)
	{
		if(x<n->data) n=n->lchild;
		else n=n->rchild;
	}
	if(r->lchild==NULL)
	{
		r->lchild=n;
		n->rchild=r->lchild->lchild;
		r->lchild->lchild=NULL;
	}
	else
	{
		if(r->rchild==NULL)
		{
			r->rchild=n;
			n->lchild=r->rchild->rchild;
			r->rchild->rchild=NULL;
		}
	}
}
void rotatedouble(avl &t,int x)
{
	avl r=t;
	avl n=t;
	while(r->data!=x)
	{
		if(x<r->data) r=r->lchild;
		else r=r->rchild;
	}
	while((n->lchild->data!=x)|(n->rchild->data!=x))
	{
		if(x<n->data) n=n->lchild;
		else n=n->rchild;
	}
	if(r->lchild==NULL)
	{
		n->rchild=r->rchild->lchild;
		n->rchild->rchild=r->rchild;
		n->lchild->lchild=r;
		r->lchild=NULL;
	}
	else
	{
		n->lchild=r->lchild->rchild;
		n->lchild->lchild=r->lchild;
		n->rchild->rchild=r;
		r->rchild=NULL;
	}
}
void insert(avl &t,int x)
{
	if(t==NULL)
	{
		t=new(struct node);
		t->data=x;
		t->lchild=NULL;
		t->rchild=NULL;
	}
	else
	{

		if(x<t->data) insert(t->lchild,x);
		else insert(t->rchild,x);
	}
}



void create(avl &t)
{
	int x,i=0;
	cout<<"enter first data"<<endl;
	cin>>x;
	while(x)
	{
		if(i==0)
		{
			avl temp=new(struct node);
			temp->lchild=NULL;
			temp->rchild=NULL;
			temp->data=x;
			t=temp;
			i++;
		}
		else
		{
			if(x<t->data)
			{

				insert(t->lchild,x);
				k=correct(t);
				while(k!=0&&r!=NULL)
				{
					r=r->lchild;
					k=correct(r);
				}
				if(k==0)
				{
					if(x<r->data&&x<r->lchild->data))
					{
						single(t,r->data);
					}
					else if(x<r->data&&x>r->child->data)
					{
						rotatedouble(t,r->data);
					}
				}
			}
		       //	else if(x>t->data)
		}
		cout<<"enter next number"<<endl;
		cin>>x;
	}
}
int main()
{
