#include<iostream.h>
#include<stdio.h>
#include<conio.h>
int main()
{
 clrscr();
 int i=0;
 char s[50],s1[50],*p;
 while(i<6)
 {
  cout<<"enter:";
  cin>>s[i];
  i++;
 }
 p=s;
// s1=p;
 cout<<p;
 cout<<"\n"<<s;
 getch();
 return 0;
}