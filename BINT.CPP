#include<iostream.h>
#include<stdlib.h>
struct node
{
int data;
struct node* lchild;
struct node* rchild;
};
typedef struct node* bsptr;
bsptr p,q;
void insert(bsptr &root)
{
int d,i=0;
bsptr temp;
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
}
cout<<"enter another number";
cin>>d;
}
}
int search(bsptr a,int x)
{
bsptr t=a;
if(t!=NULL)
{
if(t->data==x)  return 1;
else if(x<t->data)    return search(t->lchild,x);
else return search(t->rchild,x);
}
return 0;
}
int findmax(bsptr a)
{
bsptr t=a;
if(t!=NULL)
{
while(t->rchild!=NULL)
t=t->rchild;
return t->data;
}
else return 0;
}
void inorder(bsptr a)
{
bsptr t=a;
if(t!=NULL)
{
inorder(t->lchild);
cout<<t->data<<" ";
inorder(t->rchild);
}
}
void preorder(bsptr a)
{
bsptr t=a;
if(t!=NULL)
{
cout<<t->data<<" ";
preorder(t->lchild);
preorder(t->rchild);
}
}
void postorder(bsptr a)
{
bsptr t=a;
if(t!=NULL)
{
postorder(t->lchild);
postorder(t->rchild);
cout<<t->data<<" ";
}
}


int main()
{
bsptr a;
int b;
insert(a);
/*cout<<"enter number to be searched for\n";
cin>>b;
cout<<search(a,b);
cout<<"\nthe max number is"<<findmax(a)<<" ";   */
cout<<"inorder is";inorder(a);
 cout<<"preorder is";preorder(a);
 cout<<"postorder is";postorder(a);
 return 0;
 }
