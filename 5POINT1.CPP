#include<iostream.h>
#include<string.h>
struct node
{
int tag;
union
{
char atom[20];
struct node *subnode;
}
element;
struct node *next;
};
typedef struct node* nptr;
struct stack
{
nptr elements[50];
int top;
int size;
};
typedef struct stack STK;
void initialise(STK &s)
{
s.top=-1;
s.size=49;
}
void push(STK &s,nptr x)
{
if(s.top==s.size) cout<<"stack is full";
else s.elements[++s.top]=x;
}
nptr pop(STK &s)
{
if(s.top==-1)
{
nptr p;
p=NULL;
return p;
}
else return s.elements[s.top--];
}
STK s;
void insert(nptr &p)
{
initialise(s);
nptr ptr,currptr,ptr1,currptr1;
int y,j=0;
char c[50];
cout<<"enter an expression";
cin.getline(c,50);
p=new(struct node);
p->next=NULL;
int m=0;
int len=strlen(c);
for(int i=0;i<len;i++)
    {
    if(c[i]=='('||c[i]==')') y=0;
    else y=1;
    if(y==1)
     {
     if(j==0)
       {
       if(c[i]!=',')
       {
       p->tag=1;
       p->element.atom[m++]=c[i];
       }
       if(c[i]==',')
       {
       j++;
       m=0;
       ptr=new(struct node);
       p->next=ptr;
       currptr=ptr;
       ptr->next=NULL;
       }
       }
     else  if(j==1)
      {
      if(c[i]!=',')
       {
       ptr->tag=1;
       ptr->element.atom[m++]=c[i];
       }
  else  if(c[i]==',')
       {
       m=0;
       currptr=new(struct node);
       ptr->next=currptr;
       currptr->next=NULL;
       ptr=currptr;
    }
    }
    }
     else if(y==0)
       {
       if(c[i]=='(')
	 {
	 if(j==0)
	   {
	   p->tag=0;
	   ptr=new(struct node);
	   p->element.subnode=ptr;
	   ptr->next=NULL;
	   currptr=ptr;
	   ptr1=new(struct node);
	   p->next=ptr1;
	   ptr1->next=NULL;
	   push(s,ptr1);
	   j++;
	   }
	 else
	   {
	   ptr->tag=0;
	   currptr=new(struct node);
	   ptr->element.subnode=currptr;
	   currptr->next=NULL;
	   ptr1=new(struct node);
	   ptr->next=ptr1;
	   ptr1->next=NULL;
	   push(s,ptr1);
	   ptr=currptr;
	   }
	 }
       else if(c[i]==')')
       {
       ptr1=pop(s);
       ptr=ptr1;
       currptr=ptr1;
       }
     }
    }
  /*  nptr a=p;
    while(a->next!=NULL)
    {
    cout<<a->element.atom;
    a=a->next;
    }
    cout<<endl;   */
    }

int l,d=0;
void print(nptr &p)
{
nptr a=p;
while(a->next!=NULL&&a->tag==1)
    {
    l=strlen(a->element.atom);
    cout<<a->element.atom;
    a=a->next;
    }
    d=d+l;
if(a->next!=NULL&&a->tag==0)
 {
 nptr b=a->next;
 cout<<endl;
 while(d)
 {
 cout<<" ";
 d=d-1;
 }

 print(a->element.subnode);
  while(b->next!=NULL)
 {
 cout<<endl;
 while(d-1)
 {
 cout<<" ";
 d--;
 }
 int r=strlen(b->element.atom);
 for(int o=0;o<r;o++)
 cout<<b->element.atom[o];
 b=b->next;
 }
}
}
int main()
{
nptr p;
insert(p);
print(p);
return 0;
}
