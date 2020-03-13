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
int printnodes(btptr p)
{
if(p==NULL)  return 0;
else if(p->lchild==NULL&&p->rchild==NULL)
return 0;
else return 1+printnodes(p->lchild)+printnodes(p->rchild);
}
int printnode(btptr p)
{
if(p->lchild==NULL&&p->rchild==NULL)
return 1;
else return printnode(p->lchild)+printnode(p->rchild);
}
int main()
{
btptr p;
create(p);
cout<<printnode(p);
return 0;
}