#include<iostream.h>
void print(int n,int j)
{
cout<<j;
if(n==1)  cout<<"1";
else
{
for(int k=1;k<n;k++)
{
print(n-k,k);cout<<" ";
}
}
}
int main()
{
int a;
cout<<"enter a number";
cin>>a;
print(a,1);
return 0;
}