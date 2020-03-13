#include<iostream.h>
#include<stdlib.h>
struct node
{
int data;
struct node* lchild;
struct node* rchild;
};
typedef struct node* nptr;
nptr temp,p,q,t1,t2;
int max(int x,int y)
{
if(x>y)  return x;
else return y;
}
int height(nptr& p)
{
if(p==NULL)  return -1;
else return max(height(p->lchild),height(p->rchild))+1;
}
int avlcond(nptr& p)
{
int a,b;
a=height(p->lchild);
b=height(p->rchild);
if(a==b||a==b+1||a+1==b)  return 1;
else return 0;
}
void arrange(nptr& a,nptr& b,int d)
{
int y,z;
nptr t,t1,t2,t3,t4;
while(avlcond(b)!=0&&b!=a)
{
t=a;
while(t->lchild!=b&&t->rchild!=b)
{
if(d>t->data) t=t->rchild;
else t=t->lchild;
}
b=t;
}
if(avlcond(b)==0)
{
t1=b;
if(d>t1->data)
{
t2=t1->rchild;
y=1;
}
else
{
t2=t1->lchild;
y=0;
}
if(d>t2->data)
{
t3=t1->rchild;
z=1;
}
else
{
t3=t1->lchild;
z=0;
}
if(y==1&&z==1)
{
t1->rchild=t2->lchild;
t2->lchild=t1;
}
if(y==0&&z==0)
{
t1->lchild=t2->rchild;
t2->rchild=t1;
}
if(y==1&&z==0)
{
t1->rchild=t3->lchild;
t2->lchild=t3->rchild;
t3->lchild=t1;
t3->rchild=t2;
}
if(y==0&&z==1)
{
t2->rchild=t3->lchild;
t1->lchild=t3->rchild;
t3->lchild=t2;
t3->rchild=t1;
}
if(b!=a)
{
t=a;
while(t->lchild!=b&&t->rchild!=b)
{
if(d>t->data)  t=t->rchild;
else t=t->lchild;
}
if(d>t->data) t->rchild=t2;
else t->lchild=t2;
}
else
{
if(y==z) a=t2;
else a=t3;
}
}
}
void insert(nptr &root)
{
int d,i=0;
nptr temp;
cout<<"enter the number";
cin>>d;
while(d)
{
temp=new(struct node);
temp->data=d;
temp->lchild=NULL;
temp->rchild=NULL;
if(i==0)
{
root=temp;
i++;
}
else
{
p=root;
while(p!=NULL)
{
q=p;
if(d>p->data)  p=p->rchild;
else p=p->lchild;
}
if(d>q->data) q->rchild=temp;
else q->lchild=temp;
arrange(root,q,d);
}
cout<<"enter another number";
cin>>d;
}
}
int main()
{
nptr a;
insert(a);
cout<<height(a);
return 0;
}
