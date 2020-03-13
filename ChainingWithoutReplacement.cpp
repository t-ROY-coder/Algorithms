#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct str {
           char name[10];
           int r,next;
           str()
           {
                 name[0]='\0';
                 r=next=-1;
           }
           }s[20],t[20];
fstream fil;
void getd()
{
     char ch;
     int i,r;
     do {
         cout<<"Roll number:";
         cin>>r;
         i=r%20;
         while(s[i].r!=-1)
         i++;
         s[i].r=r;
         cout<<"Name:";
         cin>>s[i].name;
         if(r%20!=i)
         {
         int n1;
         for(n1=r%20;s[n1].next!=-1;n1=s[n1].next);
         s[n1].next=i;
         }
         cout<<"More?(Y/N):";
         cin>>ch;
         }while(ch=='y' || ch=='Y');
     fil.open("Temp.txt",ios::out);
     fil.write((char*)&s,20*sizeof(str));
     fil.close();
}
void find()
{
     int r;
     cout<<"Enter roll number:";
     cin>>r;
     fil.open("Temp.txt",ios::in);
     fil.read((char*)&t,20*sizeof(str));
     fil.close();
     int i=r%20;
     while(t[i].r!=r)
     i=t[i].next;
     cout<<t[i].r<<"\t"<<t[i].name;
}
int main()
{
    getd();
    find();
    cin.get();
    cin.get();
    return 0;
}
