#include<iostream>
#include<cmath>
using namespace std;
struct bstnode {
               char d;
               bstnode *right,*left;
               bstnode(char a='\0')
               {
                            d=a;
                            right=left=NULL;
               }
               };
typedef bstnode* PTR;
template<class T>
class queue
{
               T a[100];
               int front,rear;
               public:
                      queue()
                      {
                               front=rear=-1;
                      }
                      void enqueue(T n)
                      {
                           if(front==-1 && rear==-1)
                           {
                                        front=rear=0;
                                        a[rear]=n;
                           }
                           else if((rear+1)%100==front)
                           cout<<"Full!\n";
                           else
                           {
                               rear=(rear+1)%100;
                               a[rear]=n;
                           }
                      }
                      T dequeue()
                      {
                                 if(front==-1)
                                 cout<<"Empty!\n";
                                 else if(front==rear)
                                 {
                                      T t=a[front];
                                      front=rear=-1;
                                      return t;
                                 }
                                 else
                                 {
                                     T t=a[front];
                                     front=(front+1)%100;
                                     return t;
                                 }
                                 //return 0;
                      }
                      T* getit()
                      {
                                return a;
                      }
};
template<class L>
void crt(PTR &T, queue<L> &q)
{
     char l,r;
     if(T==NULL)
     {
                char ch=q.dequeue();
                cout<<ch<<(int)ch<<endl;
                if(ch!='o')
                {
                           T=new bstnode(ch);
                           cout<<"Enter "<<ch<<"'s children:";
                           cin>>l>>r;
                }
     }
     if(l!='o')
     {
               q.enqueue(l);
               crt(T->left,q);
     }
     if(r!='o')
     {
               q.enqueue(r);
               crt(T->right,q);
     }
}
int compare(PTR a, PTR b)
{
    if(a==NULL && b==NULL)
    return 1;
    else if(a!=NULL && b!=NULL)
    if(a->d!=b->d)
    return 0;
    else
    {
        int i=compare(a->left,b->left);
        int j=compare(a->right,b->right);
        return i*j;
    }
    else
    return 0;
}
int intnodes(PTR a, int n=0)
{
    if(a->right==NULL && a->left==NULL)
    return n;
    else
    {
        int i=0,j=0;
        if(a->right!=NULL)
        i=intnodes(a->right,n);
        if(a->left!=NULL)
        j=intnodes(a->left,n);
        return n+i+j+1;
    }
}
int extnodes(PTR a, int n=0)
{
    int i=0,j=0;
    if(a->right!=NULL || a->left!=NULL)
    {
                      if(a->right!=NULL)
                      i=extnodes(a->right,n);
                      if(a->left!=NULL)
                      j=extnodes(a->left,n);
                      return n+i+j;
    }
    if(a->left==NULL && a->right==NULL)
    return n+1;
}
PTR temp=NULL;
template<class T>
void find(PTR t,T a)
{
    if(t->d==a)
    temp=t;
    else if(t->right!=NULL || t->left!=NULL)
    {
         if(t->right!=NULL)
         find(t->right,a);
         if(t->left!=NULL)
         find(t->left,a);
    }
}
PTR s;
void lvlprn(queue<PTR> &q)
{
     PTR tmp=q.dequeue(),tmp2=new bstnode;
     while(tmp!=tmp2)
     {
     if(tmp==NULL)
     {
                  cout<<endl;
                  q.enqueue(NULL);
     }
     else
     {
         cout<<tmp->d;
         if(tmp->left!=NULL)
         q.enqueue(tmp->left);
         if(tmp->right!=NULL)
         q.enqueue(tmp->right);
     }
     tmp2=tmp;
     tmp=q.dequeue();
     }
}
int depth(PTR t,queue<PTR> &q,char ch)
{
    q.enqueue(t);
    q.enqueue(NULL);
    int i=-1;
    char a[100];
    PTR tmp=q.dequeue(),tmp2=new bstnode;
     while(tmp!=tmp2)
     {
     if(tmp==NULL)
     {
                  //cout<<endl;
                  q.enqueue(NULL);
                  a[++i]='.';
     }
     else
     {
         //cout<<tmp->d;
         a[++i]=tmp->d;
         if(tmp->left!=NULL)
         q.enqueue(tmp->left);
         if(tmp->right!=NULL)
         q.enqueue(tmp->right);
     }
     tmp2=tmp;
     tmp=q.dequeue();
     }
     a[++i]='\0';
     int d=0,j;
     for(j=0;j<strlen(a);j++)
     if(a[j]=='.')
     d++;
     else if(a[j]==ch)
     break;
     if(j==strlen(a))
     cout<<"Not found!\n";
     else
     return d;
     return -1;
}
int totch(PTR t)
{
    if(t!=NULL)
    return (intnodes(t)+extnodes(t));
    return 0;
}
int max(int a, int b)
{
    if(a>b)
    return a;
    return b;
}
int height(PTR p)
{
    if(p==NULL)
    return -1;
    else
    return(max(height(p->left),height(p->right))+1);
}
/*PTR p[100];
char chr[100];
int nm[100],i=-1,j=-1,k=-1;
void display(PTR t, int ref=0)
{
     for(int n=0;n<100;n++)
     {
             p[i]=NULL;
             chr[i]='\0';
             nm[i]=-1;
     }
     int ft=0;
     p[++i]=t;
     p[++i]=NULL;
     nm[++j]=totch(t->left);
     PTR tmp2=NULL,tmp=p[ft++];
     while(tmp!=tmp2)
     {
                     //cout<<"IN";
                     if(tmp==NULL)
                     {
                                  //cout<<"If\n";
                                  p[++i]=NULL;
                     }
                     else
                     {
                         //cout<<"Else\n";
                         chr[++k]=tmp->d;
                         //cout<<chr[k]<<endl;
                         if(tmp->left!=NULL)
                         {
                         p[++i]=tmp->left;
                         nm[++j]=totch(tmp->left->left)+ref;
                         }
                         if(tmp->right!=NULL)
                         {
                         p[++i]=tmp->right;
                         ref=totch(tmp->left->left)+ref;
                         nm[++j]=totch(tmp->right->left)+totch(tmp->left->right)+ref+1;
                         }
                     }
                     tmp2=tmp;
                     tmp=p[ft++];
     }
     int fl=0;
     for(int n=0;!(p[n]==NULL && p[n+1]==NULL);n++)
     {
             //cout<<n<<endl;
             if(p[n]!=NULL)
             {
                           for(int w=0;w<nm[fl];w++)
                           cout<<" ";
                           cout<<p[n]->d;
                           fl++;
             }
             else
             cout<<endl;
     }
     /*cout<<endl;
     if(t!=NULL)
     {
                //for(int i=0;i<(totch(t->left)+ref);i++)
                //cout<<"\t";
                //cout<<t->d;
                if(t->left!=NULL)
                {
                display(t->left,ref);
                //cout<<endl;
                }
                if(t->right!=NULL)
                {
                display(t->right,totch(t->left)+1);
                //cout<<endl;
                }
     }*/
/*}*/
void display(PTR t,int ref=0)
{
     queue<PTR> q1;
     queue<int> q2;
     q1.enqueue(t);
     q1.enqueue(NULL);
     PTR t1=q1.dequeue(),t2=NULL;
     int s=(int)pow((double)2,(double)height(t1))-1;
     q2.enqueue(s);
     while(t1!=t2)
     {
                  if(t1==NULL)
                  {
                              cout<<endl;
                              q1.enqueue(NULL);
                  }
                  else
                  {
                      int h=height(t1);
                      s=q2.dequeue();
                      //cout<<s<<endl;
                      for(int i=0;i<s;i++)
                      cout<<" ";
                      cout<<t1->d;
                      if(t1->left!=NULL)
                      {
                                        q1.enqueue(t1->left);
                                        q2.enqueue((int)pow((double)2,(double)height(t1->left))-1+ref);
                      }
                      if(t1->right!=NULL)
                      {
                                         q1.enqueue(t1->right);
                                         //ref=(int)pow((double)2,(double)height(t1->left))-1;
                                         q2.enqueue((int)pow((double)2,(double)height(t1))+(int)pow((double)2,(double)height(t1->left))+ref);
                      }
                  }
                  t2=t1;
                  t1=q1.dequeue();
     }
}
int main()
{
    queue <char> q;
    s=NULL;
    char ch;
    cout<<"Enter root node:";
    cin>>ch;
    q.enqueue(ch);
    crt(s,q);
    //cin>>ch;
    //find(s,ch);
    //if(temp!=NULL)
    //cout<<temp->d;
    queue<PTR> q2;
    //q2.enqueue(s);
    //q2.enqueue(NULL);
    //lvlprn(q2);
    //depth(s,q2);
    //cout<<intnodes(s);
    //cout<<extnodes(s);
    //do {
    //cin>>ch;
    //cout<<depth(s,q2,ch);
    //cout<<n<<endl;
    //}while(ch!='o');
    display(s);
    cin.get();
    cin.get();
    return 0;
}
