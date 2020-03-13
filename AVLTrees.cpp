#include<iostream>
using namespace std;
typedef struct node {
                    int d;
                    node *left,*right;
                    node(int i=-1)
                    {
                             d=i;
                             left=right=NULL;
                    }
                    }*PTR;
int max(int a,int b)
{
    if(a>b)
    return a;
    return b;
}
int ht(PTR a)
{
    if(a==NULL)
    return -1;
    return(max(ht(a->left),ht(a->right))+1);
}
int mod(int a)
{
    if(a<0)
    return -a;
    return a;
}
void lsr(PTR &a)
{
     PTR b=a->left;
     a->left=b->right;
     b->right=a;
     a=b;
}
void rsr(PTR &a)
{
     PTR b=a->right;
     a->right=b->left;
     b->left=a;
     a=b;
}
void ldr(PTR &a)
{
     PTR b=a->left,c=a->left->right;
     b->right=c->left;
     a->left=c->right;
     c->left=b;
     c->right=a;
     a=c;
}
void rdr(PTR &a)
{
     PTR b=a->right,c=a->right->left;
     b->left=c->right;
     a->right=c->left;
     c->right=b;
     c->left=a;
     a=c;
}
void crt(PTR &a, int n)
{
     if(a==NULL)
     {
                a=new node(n);
                a->left=a->right=NULL;
     }
     else if(n<a->d)
     {
          crt(a->left,n);
          if(mod(ht(a->left)-ht(a->right))>1)
          if(n<a->left->d)
          lsr(a);
          else if(n>a->left->d)
          ldr(a);
     }
     else if(n>a->d)
     {
          crt(a->right,n);
          if(mod(ht(a->left)-ht(a->right))>1)
          if(n>a->right->d)
          rsr(a);
          else if(n<a->right->d)
          rdr(a);
     }
}
void prn(PTR a)
{
     if(a!=NULL)
     {
                prn(a->left);
                cout<<a->d<<" ";
                prn(a->right);
     }
}
void prn2(PTR a)
{
     if(a!=NULL)
     {
                cout<<a->d<<" ";
                prn2(a->left);
                prn2(a->right);
     }
}
int diff(PTR t)
{
    if(t!=NULL)
    return (ht(t->left)-ht(t->right));
    return 0;
}
int findmin(PTR T)
{
    if(T==NULL)
    cout<<"Empty!";
    else if(T->left==NULL)
    return T->d;
    else
    return (findmin(T->left));
}
void balance(PTR &t)
{
     if(diff(t)==2)
     {
                   if(diff(t->left)==0 || diff(t->left)==1)
                   lsr(t);
                   else if(diff(t->left)==-1)
                   ldr(t);
     }
     else if(diff(t)==-2)
     {
                   if(diff(t->right)==0 || diff(t->right)==1)
                   rsr(t);
                   else if(diff(t->right)==-1)
                   rdr(t);
     }
}
void del(PTR &t, int n)
{
     if(t==NULL);
     else if(n<t->d)
     {
          del(t->left,n);
          balance(t->left);
     }
     else if(n>t->d)
     {
          del(t->right,n);
          balance(t->right);
     }
     else if(t->right!=NULL && t->left!=NULL)
     {
          t->d=findmin(t->right);
          del(t->right,t->d);
          balance(t->right);
     }
     else
     {
         PTR T=t;
         if(t->right==NULL)
         t=t->left;
         else if(t->left==NULL)
         t=t->right;
         delete T;
         balance(t);
     }
}
int main()
{
    PTR s=NULL;
    int i;
    cout<<"Enter the numbers one-by-one:";
    cin>>i;
    while(i)
    {
            crt(s,i);
            cin>>i;
    }
    cout<<"Delete:";
    cin>>i;
    del(s,i);
    prn(s);
    cout<<endl;
    prn2(s);
    cin.get();
    cin.get();
    return 0;
}
