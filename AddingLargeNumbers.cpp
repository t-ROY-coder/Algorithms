#include<iostream>
#include<cmath>
using namespace std;
struct node {
             int n;
             node *right;
             };
typedef node* PTR;
PTR P,Q,R;
PTR findlast(PTR p)
{
    if(p!=NULL)
    while(p->right!=NULL)
                        p=p->right;
    return p;
}
void addnode(int flg, int v=0)
{
     PTR t=new node;
     t->n=v;
     if(flg==0)
     {
               t->right=P;
               P=t;
               }
     else if(flg==1)
     {
          t->right=Q;
          Q=t;
          }
     else if(flg==2)
     {
          t->right=R;
          R=t;
          }
}
void add(PTR p, PTR q, int i)
{
     int carry=0;
     while(q!=NULL && p!=NULL)
     {
                         addnode(2);
                         R->n=((p->n)+(q->n)+carry)%((int)(pow((double)10,i)));
                         carry=((p->n)+(q->n)+carry)/((int)(pow((double)10,i)));
                         p=p->right;
                         q=q->right;
     }
     if(q!=NULL && p==NULL)
     while(q!=NULL)
     {
                addnode(2,((q->n+carry)%((int)(pow((double)10,i)))));
                carry=((q->n)+carry)/((int)(pow((double)10,i)));
                q=q->right;
                }
     else if(p!=NULL && q==NULL)
     while(p!=NULL)
     {
                   addnode(2,((p->n+carry)%((int)(pow((double)10,i)))));
                   carry=((p->n)+carry)/((int)(pow((double)10,i)));
                   p=p->right;
          }
     if(p==NULL && q==NULL)
     if(carry)
              addnode(2,carry);
}
void prn(PTR T, int i)
{
     PTR C=T;
     while(C->right->right!=NULL)
     C=C->right;
     if(C->right->n)
     cout<<C->right->n;
     delete C->right;
     C->right=NULL;
     while(T->right!=NULL)
     {
                         C=T;
                         while(C->right->right!=NULL)
                                                   C=C->right;
                         for(int n=i-1;n>=0;n--)
                                 if(C->right->n<(int)pow((double)10,n))
                                                                       cout<<"0";
                         if(C->right->n)
                         cout<<C->right->n;
                         delete C->right;
                         C->right=NULL;
                         }
     for(int n=i-1;n>=0;n--)
                                 if(T->n<(int)pow((double)10,n))
                                                                       cout<<"0";
     if(T->n)
     cout<<T->n;
}
int main()
{
    P=Q=R=NULL;
    int i,j;
    addnode(0,0);
    addnode(1,0);
    cout<<"Enter the digits in a node:";
    cin>>i;
    cout<<"Enter the first number ("<<i<<" digits at a time, -1 to stop):";
    cin>>j;
    while(j!=-1)
    {
           addnode(0,j);
            cin>>j;
    }
    cout<<"Enter the second number ("<<i<<" digits at a time, -1 to stop):";
    cin>>j;
    while(j!=-1)
    {
            addnode(1,j);
            cin>>j;
    }
    add(P,Q,i);
    prn(P,i);
    cout<<" + ";
    prn(Q,i);
    cout<<" = ";
    PTR T;
    cout<<R->n;
    while(T!=NULL)
    {
    for(T=R->right;T!=NULL;T=T->right)
    {
    for(int n=i-1;n>=0;n--)
        if(T->n<(int)pow((double)10,n))
              cout<<"0";
      	if(T->n)
            	cout<<T->n;
                         }
                         }
    char ch;
    cin>>ch;
    return 0;
}
