#include<iostream>
using namespace std;
struct bstnode {
               int d;
               bstnode *left,*right;
               bstnode(int x=-1)
               {
                           d=x;
                           left=right=NULL;
               }
               };
typedef bstnode* PTR;
int search(PTR T, int x)
{
    if(T==NULL)
    cout<<"Empty!";
    else if(T->d==x)
    return 1;
    else if(x<T->d)
    return(search(T->left,x));
    else if(x>T->d)
    return(search(T->right,x));
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
int findmax(PTR T)
{
    if(T==NULL)
    cout<<"Empty!";
    else if(T->right==NULL)
    return T->d;
    else
    return(findmax(T->right));
}
void crt(PTR &T,int x)
{
     if(T==NULL)
     T=new bstnode(x);
     else if(x<T->d)
     crt(T->left,x);
     else if(x>T->d)
     crt(T->right,x);
}
void prn(PTR T)
{
     if(T!=NULL)
     {
                prn(T->left);
                cout<<" "<<T->d;
                prn(T->right);
     }
}
void del(PTR &T,int x)
{
     if(T==NULL)
     cout<<"Empty!";
     else if(x<T->d)
     del(T->left,x);
     else if(x>T->d)
     del(T->right,x);
     else if(T->left!=NULL && T->right!=NULL)
     {
          T->d=findmin(T->right);
          del(T->right,T->d);
     }
     else
     {
         PTR t=T;
         if(T->right==NULL)
         T=T->left;
         else if(T->left==NULL)
         T=T->right;
         delete t;
     }
}
int main()
{
    int i;
    PTR S=NULL;
    cin>>i;
    while(i!=-1)
    {
                crt(S,i);
                cin>>i;
    }
    cout<<endl<<findmin(S);
    cout<<endl<<findmax(S);
    cout<<endl<<search(S,5);
    del(S,6);
    prn(S);
    cin.get();
    cin.get();
    return 0;
}
