#include<iostream>
#include<fstream>
using namespace std;
fstream fil[10];
int a[5];
void swap(int &a, int &b)
{
     int t=a;
     a=b;
     b=t;
}
void bbsort(int *a)
{
     for(int i=0;i<5;i++)
     for(int j=0;j<5-i-1;j++)
     if(a[j]>a[j+1])
     swap(a[j],a[j+1]);
}
char ch[7];
char* fname(int i)
{
      ch[0]='f';
      ch[1]=char(i+48);
      ch[2]='\0';
      strcat(ch,".txt");
      return ch;
}
void sortfiles(int s)
{
//     cout<<"Sortfiles"<<s<<endl;
     for(int k=0,n=s%10;k<5;n++,k++)
     {
             fil[n].open(fname(n),ios::in|ios::out);
             fil[n].read((char*)&a,5*sizeof(int));
             bbsort(a);
             fil[n].seekp(0,ios::beg);
             fil[n].write((char*)&a,5*sizeof(int));
             fil[n].close();
     }
//     cout<<"End sortfiles\n";
}
void createfiles(int s)
{
//     cout<<"Createfiles"<<s<<endl;
     for(int k=0,o=s%10;k<5;o++,k++)
     fil[o].open(fname(o),ios::in);
     for(int k=0,n=(s+5)%10;k<5;n++,k++)
     {
             fil[n].open(fname(n),ios::out);
             for(int k=0,m=s%10;k<5;m++,k++)
             fil[m].read((char*)&a[k],sizeof(int));
             fil[n].seekp(0,ios::beg);
             fil[n].write((char*)&a,5*sizeof(int));
             fil[n].close();
     }
     for(int k=0,o=s%10;k<5;o++,k++)
     fil[o].close();
//     cout<<"End createfiles\n";
}
int issorted(int n)
{
    int l,s,flag=1;
    n%=10;
    //for(int i=0,m=n;i<10;i++,m++)
    //fil[i].open(fname(i),ios::in);
    for(int i=0,m=n;i<4;i++,m++)
    {
            fil[m].open(fname(m),ios::in);
            fil[m].read((char*)&a,5*sizeof(int));
            fil[m].close();
            l=a[4];
            fil[m+1].open(fname(m+1),ios::in);
            fil[m+1].read((char*)&a,5*sizeof(int));
            fil[m+1].close();
            s=a[0];
            if(s<l)
            {
                   flag=0;
                   break;
            }
    }
    //for(int i=0,m=n;i<10;i++,m++)
    //fil[i].close();
    //cout<<flag<<endl;
    return flag;
}
int main()
{
    for(int j=0;j<5;j++)
    {
            fil[j].open(fname(j),ios::out);
            for(int k=0;k<5;k++)
            cin>>a[k];
            fil[j].write((char*)&a,sizeof(a));
            fil[j].close();
    }
    for(int i=0;1;i++)
    {
            sortfiles(i*5);
            if(issorted(i*5)==1)
            break;
            createfiles(i*5);
    }
    for(int n=0;n<10;n++)
    {
            cout<<endl;
            fil[n].open(fname(n),ios::in);
            for(int j=0;j<5;j++)
            a[j]=-1;
            fil[n].read((char*)&a,sizeof(a));
            for(int j=0;j<5;j++)
            cout<<a[j]<<" ";
            fil[n].close();
    }
    cin.get();
    cin.get();
    return 0;
}
