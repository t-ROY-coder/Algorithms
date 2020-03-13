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
           }s[20],t[20],k,temp;
fstream fil;
void getd()
{
     char ch;
     int i,r;
     do {
         cout<<"Roll number:";
         cin>>k.r;
         cout<<"Name:";
         cin>>k.name;
         int i=r%20;
         if(k.r%20!=s[i].r%20)
         {
                              temp=s[i];
                              s[i]=k;
                              int j=i;
                              while(s[i].r!=-1)
                              i++;
                              s[i]=temp;
                              int n1;
                              for(n1=k.r%20;s[n1].next!=-1;n1=s[n1].next);
                              s[n1].next=i;
                              cout<<"Saved1\n";
         }
         else
         {
             int j=i;
             while(s[i].r!=-1)
             i++;
             s[i]=k;
             if(j!=i)
             s[j].next=i;
             cout<<"Saved2\n";
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
     {
     i=t[i].next;
     //cout<<"Doing\n";
     }
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
