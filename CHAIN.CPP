#include<iostream.h>
#include<fstream.h>
#include<string.h>
struct record
{
int rno;
char name[10];
int fptr;
int bptr;
};
int hash(int a)
{
return a%10;
}
void start(fstream& f)
{
int i;
for(i=0;i<200;i++)
f<<" ";
for(i=0;i<10;i++)
{
f.seekp(i*20,ios::beg);
f<<"#";
}
}
void insert(fstream& f)
{
int l,m,n,k,j,q,r;
char ch;
record rec,rec1;
cout<<"enter the rollnumber";
cin>>rec.rno;
cout<<"enter the name";
cin.get(ch);
cin.getline(rec.name,10);
rec.fptr=-1;
rec.bptr=-1;
l=hash(rec.rno);
f.seekp(l*20,ios::beg);
f.get(ch);
if(ch=='#')
{
f.seekp(-1,ios::cur);
f<<rec.rno<<"|"<<rec.name<<"|"<<rec.fptr<<"|"<<rec.bptr<<"|";
}
else
{
f.seekp(-1,ios::cur);
f>>m;
n=hash(m);
if(n==l)
{
do
{
f.seekp(n*20,ios::beg);
k=0;
while(k<2)
{
f.get(ch);
if(ch=='|')  k++;
}
f>>j;
cout<<"value of forward pointer is"<<j;
if(j>=0)  n=j;
}
while(j>=0);
q=n;
if(j<0)
{
n=(n+1)%10;
do
{
f.seekp(n*20,ios::beg);
f.get(ch);
if(ch!='#') n=(n+1)%10;
}
while(ch!='#');
}
rec.bptr=q;
cout<<n;
f.seekp(q*20,ios::beg);
k=0;
while(k<2)
{
f.get(ch);
if(ch=='|')  k++;
cout<<k<<endl;
}
f<<n<<"|";
f.seekp(n*20,ios::beg);
f<<rec.rno<<"|"<<rec.name<<"|"<<rec.fptr<<"|"<<rec.bptr<<"|";
}
else
{
}
}
}
int main()
{
fstream file;
file.open("ch.txt",ios::in|ios::out);
start(file);
insert(file);
insert(file);
insert(file);
return 0;
}