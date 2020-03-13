#include<iostream.h>
struct stack
{
int elements[100];
int top1;
int top2;
};
typedef struct stack STK;
void initialise(STK &s)
{
s.top1=-1;
s.top2=100;
}
void push(STK &s,int n,int x)
{
if(s.top1+1==s.top2)    cout<<"stack is full";
else
{
if(n==1)  s.elements[++s.top1]=x;
else if(n==2)  s.elements[--s.top2]=x;
}
}
int pop(STK &s,int n)
{
if(n==1)
{
if(s.top1==-1)
{
cout<<"stack1 is empty";
return -1;
}
else  return s.elements[s.top1--];
}
else if(n==2)
{
if(s.top2==100)
{
cout<<"no elements in stack2";
return 100;
}
else return s.elements[s.top2++];
}
}
int main()
{
STK s;
push(s,1,5);
push(s,2,7);
push(s,1,2);
push(s,2,6);
cout<<pop(s,1);
cout<<pop(s,2);
return 0;
}