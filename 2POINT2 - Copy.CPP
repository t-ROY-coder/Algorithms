#include<iostream.h>
struct stack
{
int elements[200];
int top[5];
};
typedef struct stack STK;
void initialise(STK &s)
{
for(int i=0;i<5;i++)
s.top[i]=40*i-1;
}
void push(STK &s,int n,int x)
{
if(n>0&&n<6)
{
if(s.top[n-1]==40*n-1)  cout<<"stack"<<n<<"is full";
else s.elements[++s.top[n-1]]=x;
}
else cout<<"enter correct stack number";
}
int pop(STK &s,int n)
{
if(n>0&&n<6)
{
if(s.top[n-1]==40*(n-1)-1)  cout<<"stack is empty";
else return s.elements[s.top[n-1]--];
}
}
int main()
{
STK s;
initialise(s);
push(s,1,2);
cout<<pop(s,1);
return 0;
}