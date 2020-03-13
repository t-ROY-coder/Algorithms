#include<iostream.h>
struct node
{
char data;
struct node* lchild;
struct node* rchild;
};
typedef struct node* btptr;
void create(btptr & t)
{
char val;
int i;
cout<<"enter value";
cin>>val;
t=new(struct node);
t->data=val;
t->lchild=NULL;
t->rchild=NULL;
cout<<"press 1 if"<<val<<"has left child";
cin>>i;
if(i==1)  create(t->lchild);
cout<<"press 1 if"<<val<<"has right child";
cin>>i;
if(i==1)  create(t->rchild);
}
int compare(btptr& p,btptr& q)
{
int a,b;
if(p==NULL&&q==NULL)  return 1;
else if(p!=NULL&&q!=NULL)
{
if(p->data==q->data)
{
a=compare(p->lchild,q->lchild);
b=compare(p->rchild,q->rchild);
if(a==1&&b==1)  return 1;
else return 0;
}
else return 0;
}
else return 0;
}
int main()
{
btptr a,b;
cout<<"enter first tree\n";
create(a);
cout<<"enter second tree\n";
create(b);
cout<<compare(a,b);
return 0;
}