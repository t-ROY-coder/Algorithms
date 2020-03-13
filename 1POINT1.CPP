#include<iostream.h>
void reverse(int n)
{
if(n/10==0)   cout<<n;
else
{
cout<<n%10;
reverse(n/10);
}
}
int main()
{
int a;
cout<<"enter a number";
cin>>a;
reverse(a);
return 0;
}

