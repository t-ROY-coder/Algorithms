#include<iostream.h>
#include<stdlib.h>
const int m=5;
struct bnode
{
int data[m];
struct bnode* child[m];
};
typedef struct bnode* bnptr;
void swap(int& a,int& b)
{
int t=a;
a=b;
b=t;
}
void sort(int a[],int l,int n)
{
for(int j=0;j<n-l-1;j++)
{
for(int i=l;i<n-j-1;i++)
{
if(a[i]>a[i+1])
 {
 swap(a[i],a[i+1]);
 }
}
}
}
int findpos(int a[],int b,int c,int d)
{
for(int i=b;i<c;i++)
{
if(a[i]==d)  break;
}
return i;
}
void add(bnptr& r,bnptr& p,bnptr& q)
{
int d=q->data[1];
bnptr r1,r2,x,y;
r1=new (struct bnode);
r2=new (struct bnode);
int j,flag,z,o,a1;
bnptr ptr[m+1];
int a[m];
a[0]=q->data[1];
for(int i=1;i<m;i++)
a[i]=r->data[i];
sort(a,0,m);       for(z=0;z<m;z++)  cout<<a[z]<<" ";
j=findpos(a,0,m,q->data[1]);  cout<<j;  cout<<"   "<<a[m/2];
ptr[j]=q->child[0];
ptr[j+1]=q->child[1];
  for(int k=0;k<j;k++)
  ptr[k]=r->child[k];
  for(k=j+2;k<m+1;k++)
  ptr[k]=r->child[k-1];
  cout<<"its ok";
  r1->data[0]=m/2;
  r2->data[0]=m/2;
  for(k=0;k<m/2;k++)
  r1->data[k+1]=a[k];
  for(k=m/2+1;k<m;k++)
  r2->data[k-m/2]=a[k];
  for(k=0;k<m/2+1;k++)
  r1->child[k]=ptr[k];
  for(k=m/2+1;k<m;k++)
  r1->child[k]=NULL;
  for(k=m/2+1;k<m+1;k++)
  r2->child[k-m/2-1]=ptr[k];
  for(k=m/2+1;k<m;k++)
  r2->child[k]=NULL;
cout<<"its ok2";
if(r==p)
{
p=new(struct bnode);
p->data[1]=a[m/2];
p->data[0]=1;
p->child[0]=r1;
cout<<r1->data[0];
p->child[1]=r2;
cout<<"its ok3";
}
else
{
y=new(struct bnode);
y->data[0]=1;
y->data[1]=a[m/2];
for(k=0;k<m;k++)
y->child[k]=NULL;
y->child[0]=r1;
y->child[1]=r2;
x=p;
flag=0;

while(flag==0)
{
z=x->data[0];
for(o=0;o<z+1;o++)
{
if(x->child[o]==r)
{
flag=1;
break;
}
}
if(flag==0)
{
for(o=1;o<z+1;o++)
{
a1=0;
if(d<x->data[o])
{
x=x->child[o-1];
a1=1;
break;
}
}
if(a1==0)
{
if(d>x->data[z]) x=x->child[z];
}
}
}
if(x->data[0]==m-1)  add(x,p,y);
else
{
for(o=1;o<x->data[0]+1;o++)
a[o]=x->data[o];
a[0]=y->data[1];
sort(a,0,x->data[0]+1);
j=findpos(a,0,x->data[0]+1,y->data[1]);
ptr[j]=y->child[0];
ptr[j+1]=y->child[1];
for(k=0;k<j;k++)
ptr[k]=x->child[k];
for(k=j+2;k<x->data[0]+2;k++)
ptr[k]=x->child[k-1];
x->data[0]++;
for(k=1;k<x->data[0]+1;k++)
x->data[k]=a[k-1];
for(k=0;k<x->data[0]+1;k++)
x->child[k]=ptr[k];
}
cout<<"its ok4";
}
}
void insert(bnptr& p)
{
int i=0,d,j,k;
cout<<"enter the number";
cin>>d;
while(d)
{
	if(i==0)
	{
	p=new(struct bnode);
	p->data[0]=0;
	p->data[++p->data[0]]=d;
	i++;
	for(j=0;j<m;j++)
	p->child[j]=NULL;
	}
	else
	{
	bnptr r=p;
	while(r->child[0]!=NULL)
		{
		for(j=1;j<r->data[0]+1;j++)
		{
		k=0;
		if(d<r->data[j])
		{
		k=1;
		r=r->child[j-1];
		break;
		}
		}
		if(k==0)
		{
		if(d>r->data[r->data[0]]) r=r->child[r->data[0]];
		}
		}
	if(r->child[0]==NULL)
	{
	if(r->data[0]!=m-1)
	{
	r->data[++r->data[0]]=d;     cout<<r->data[0];   cout<<"value is"<<r->data[1]<<endl;
	sort(r->data,1,r->data[0]+1);
	}
	else if(r->data[0]==m-1)
	{
	bnptr q;
	q=new(struct bnode);
	q->data[0]=0;
	q->data[++q->data[0]]=d;
	for(j=0;j<m;j++)
	q->child[j]=NULL;
	add(r,p,q);
	}
	}
}
cout<<"enter the number";
cin>>d;
}
}
void rem(bnptr& p,bnptr& r,int d)
{
int i,j,z,o,flag,a1;
bnptr x;
x=r;
if(r->child[0]!=NULL)
{
for(o=1;o<r->data[0]+1;o++)
if(r->data[o]==d)  break;
r=r->child[o-1];
x->data[o]=r->data[r->data[0]];
rem(p,r,r->data[r->data[0]]);
}
else if(r->child[0]==NULL)
{
if(r->data[0]>m/2)
{
r->data[0]=r->data[0]-1;
int a[m];
for(o=1;o<r->data[0]+2;o++)
if(r->data[o]==d)   break;
for(i=1;i<o;i++)
a[i-1]=r->data[i];
for(i=o+1;i<r->data[0]+2;i++)
a[i-2]=r->data[i];
for(o=1;o<r->data[0]+1;o++)
r->data[o]=a[o-1];
}
else
{
x=p;
flag=0;
while(flag==0)
{
z=x->data[0];
for(o=0;o<z+1;o++)
{
if(x->child[o]==r)
{
flag=1;
break;
}
}
if(flag==0)
{
for(o=1;o<z+1;o++)
{
a1=0;
if(d<x->data[o])
{
x=x->child[o-1];
a1=1;
break;
}
}
if(a1==0)
{
if(d>x->data[z]) x=x->child[z];
}
}
}
for(o=0;o<x->data[0]+1;o++)
if(x->child[o]==r)   break;
if(o!=0)
{
if(x->child[o-1]->data[0]>m/2)
{
x->child[o-1]->data[0]--;
i=x->data[o];
x->data[o]=x->child[o-1]->data[x->child[o-1]->data[0]+1];
for(j=1;j<r->data[0]+1;j++)
if(r->data[j]==d)   break;
r->data[j]=i;
sort(r->data,1,r->data[0]+1);
}
else
{
int b[m-1];
for(i=0;i<m/2;i++)
b[i]=x->child[o-1]->data[i+1];
a1=r->data[0];
r->data[0]=0;
for(i=1;i<r->data[0]+1;i++)
if(r->data[i]==d)  break;
r->data[i]=0;
sort(r->data,0,a1+1);

b[m/2]=x->data[o];
for(i=m/2+1;i<m-1;i++)
b[i]=r->data[i+1-m/2];
for(i=o;i<x->data[0];i++)
x->data[i]=x->data[i+1];
for(i=1;i<m;i++)
r->data[i]=b[i-1];
r->data[0]=m-1;
x->child[o-1]=r;
for(i=o;i<x->data[0];i++)
x->child[i]=x->child[i+1];
x->data[0]--;
}
}
else if(o==0)
{
if(x->child[o+1]->data[0]>m/2)
{
x->child[o+1]->data[0]--;
i=x->data[o+1];
x->data[o+1]=x->child[o+1]->data[1];
for(j=1;j<x->child[o+1]->data[0]+1;j++)
x->child[o+1]->data[j]=x->child[o+1]->data[j+1];
for(j=1;j<r->data[0]+1;j++)
if(r->data[j]==d)   break;
cout<<j<<i<<endl;
r->data[j]=i;
sort(r->data,1,r->data[0]+1);
}
else
{
int b[m-1];
for(i=0;i<m/2;i++)
b[i]=x->child[o+1]->data[i+1];
a1=r->data[0];
r->data[0]=0;
for(i=1;i<a1+1;i++)
if(r->data[i]==d)  break;
r->data[i]=0;
sort(r->data,0,a1+1);

b[m/2]=x->data[o+1];
for(i=m/2+1;i<m-1;i++)
b[i]=r->data[i+1-m/2];
for(i=o+1;i<x->data[0];i++)
x->data[i]=x->data[i+1];
for(i=1;i<m;i++)
r->data[i]=b[i-1];
sort(r->data,1,m);
r->data[0]=m-1;
x->child[o]=r;
for(i=o+1;i<x->data[0];i++)
x->child[i]=x->child[i+1];
x->data[0]--;
}
}
}
}
}
void remove(bnptr& p,int d)
{
int flag,a1,z,o,i,j,l;
bnptr r,x;
r=p;
flag=0;
while(flag==0)
{
z=r->data[0];
for(o=1;o<z+1;o++)
{
if(r->data[o]==d)
{
flag=1;
break;
}
}
if(flag==0)
{
for(o=1;o<z+1;o++)
{
a1=0;
if(d<r->data[o])
{
r=r->child[o-1];
a1=1;
break;
}
}
if(a1==0)
{
if(d>r->data[z]) r=r->child[z];
}
}
}
rem(p,r,d);
}
struct queue
{
struct bnode* nptr;
struct queue* next;
};
typedef struct queue que;
que *temp,*ptr,*currptr;
int a2=0;
void enque(que*& q,bnptr p)
{
temp=new que;
temp->next=NULL;
temp->nptr=p;
if(q==NULL)
{
q=temp;
ptr=temp;
currptr=temp;
}
else
{
ptr=temp;
currptr->next=ptr;
currptr=ptr;
}
}
bnptr deque(que*& q)
{
que* r;
r=q;
q=q->next;
r->next=NULL;
return r->nptr;
}
void print(bnptr& p)
{
que* q;
q=NULL;
bnptr x;
int i=0,j;
enque(q,p);
x=deque(q);
while(q!=NULL||i==0)
{
i++;
if(x->child[0]!=NULL)
{
for(j=0;j<x->data[0]+1;j++)
{
enque(q,x->child[j]);
}
}
for(j=1;j<x->data[0]+1;j++)
cout<<x->data[j]<<" ";
x=deque(q);
}
for(j=1;j<x->data[0]+1;j++)
cout<<x->data[j]<<" ";
}

void inorder(bnptr& p)
{
int i;
if(p!=NULL)
{
for(i=1;i<p->data[0]+1;i++)
{
inorder(p->child[i-1]);
cout<<p->data[i]<<" ";
}

inorder(p->child[i-1]);
}
}
int main()
{
int d;
bnptr p;
insert(p);
inorder(p);
cout<<endl;
print(p);
cout<<endl;
cout<<"enter the number u want to delete";
cin>>d;
remove(p,d);
inorder(p);
cout<<endl;
print(p);
return 0;
}