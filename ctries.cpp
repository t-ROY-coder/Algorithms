#include<iostream.h>
#include<string.h>
#include<conio.h>
class ctrie
{
  public:
  struct ctrinode
  {
    int l;
    char a[5];
    int count;
    char name[10];
    ctrinode()
    {
      l=-1;
      for(int i=0;i<5;i++)
        a[i]=0;
      count=0;
    }
   };
  ctrinode c[5];
  int size;
  ctrie()
  {
   size=0;
  }
  void cpy(ctrinode *&t,int n,int m)
  {
   for(int i=n;i<m;i++)
   {
     t[i+1].l=t[i].l;
     if(t[i].l==1)
         for(int j=0;j<5;j++)
        {
         t[i+1].a[j]=t[i].a[j];
         t[i+1].count=t[i].count;
        }
      else
      {
       for(int j=0;j<10;j++)
       {
        t[i+1].name[j]=t[i].name[j];
        t[i+1].count=t[i].count;
       }
      }
      t[i].l=0;
      t[i].count=0;
      for(int j=0;j<5;j++)
         t[i].a[j]=0;
   }
  }
  int keyval(char ch)
  {
    if(ch!='!')
      return(ch-'a');
    else
      return(4);
  }
  int value(char *t,int i)
  {
   int count=0;
   for(int j=0;j<i;j++)
    if(t[j]==1)
      count++;
   return count;
  }
  int tvalue(ctrinode *&t,int n,int m)
  {
   int k=0,i;
   for(i=0;i<n;i++)
    k+=t[i].count;
   k+=value(t[i].a,m);
   return(k+1);
  }
  int compare(char *t,char *ch,int n)
  {
   int i=strlen(ch),count=0;
   for(int j=n;j<i;j++)
     if(t[j]==ch[j])
       count++;
   return count;
  }
  void insert(char *ch)
  {

   insert(ch,c,0,0);
  }

  void insert(char *ch,ctrinode *&c,int n,int m)
  {

       int i=n, j,k;
       int f=strlen(ch);
       char l=ch[m];
       j=keyval(l);
       //int v=c[i].count;
       //cout<<v;
       if(c[0].l==-1)
       {
         c[0].a[j]=1;
         c[0].l=1;
         c[0].count=1;
         for(int k=0;k<f;k++)
           c[1].name[k]=ch[k];
          c[1].l=0;
          c[1].count=f;

          size=2;

       }
       else
       {
        if(c[i].l==1)
        {
          if(c[i].a[j]==1)
          {
             i=tvalue(c,i,j);
             insert(ch,c,i,m+1);
          }
          else
          {      size++;

                 c[i].a[j]=1;
                 c[i].count+=1;
                 k=tvalue(c,i,j);
                 if(c[k].l==0||c[k].l==1)
                 {
                    cpy(c,k,size);}
                 c[k].l=0;
                 cout<<k<<" k";
                 for(int b=0;b<f;b++)
                    c[k].name[b]=ch[b];
                 c[k].count=f;
               for(int o=0;o<f;o++)
                  cout<<c[k].name[o]<<"this";
           }
         }
         else
         {


           int h=0,v=c[i].count,k;

           char *b=new char,d;
           for( k=0;k<v;k++)
           {
             b[k]=c[i].name[k];

           }
           for(int y=m;y<v;y++)
             if(ch[y]==b[y])
               h++;
           if(h==v)
             cout<<"u enter the same word\n";
           else
           {
            k=0;
            int p,g,j;
            c[i].l=0;
            c[i].count=0;
            for(int j=0;j<5;j++)
                 c[i].a[j]=0;

            while(k<h)
             {
              g=m;
              cout<<"i."<<i<<"m."<<m;
              c[i].l=1;
              c[i].a[m]=1;
              c[i].count+=1;
              i=tvalue(c,i,m);
              d=ch[m+1];
              m=keyval(d);

             if(c[i].l==1||c[i].l==0)
               cpy(c,i,size);


             k++;

            }
            cout<<i;
            size+=h;
            c[i].l=1;
            c[i].a[m]=1;
            d=b[g+1];
            p=keyval(d);
            c[i].a[p]=1;
            c[i].count+=2;
            j=i;
            i=tvalue(c,i,m);
            if(c[i].l==1||c[i].l==0)
                cpy(c,i,size);
            size+=1;
            c[i].l=0;
            c[i].count=f;
            for( int l=0;l<f;l++)
             {
               c[i].name[l]=ch[l];
               //cout<<c[i].name[l];
             }
            i=j;
            cout<<"i"<<j;
            i=tvalue(c,i,p);
            if(c[i].l==1||c[i].l==0)
                cpy(c,i,size);
            c[i].l=0;
            c[i].count=v;
            size+=1;
            for(int l=0;l<v;l++){
               c[i].name[l]=b[l];
           }   //cout<<c[i].name[l];
           }
          }
         }


}
void search(char *ch)
{
  int n,i=0,k,m=0,j=0,count=0;
  n=strlen(ch);
  char p;
  while(i<n&&m==0)
  {
      p=ch[i];
      k=keyval(p);
      if(c[j].l==1)
      {
        if(c[j].a[k]==1)
        {

         j=tvalue(c,j,k);
        }
        else
         { m=1;
           cout<<"word not found\n";
         }
       }
      else
      {

       for(int h=0;h<n;h++)
         if(c[j].name[h]==ch[h])
            count++;
       if(count==n)
       {
          cout<<"word is found\n";
          for(int h=0;h<n;h++)
            cout<<c[j].name[h];
          m=1;
       }
       else
         {
          cout<<"word is not found\n";
          m=1;
         }
      }
      i++;
   }
 }
};
int main()
{
 ctrie c;
 int k,i,j=0;
 char *ch;
 do
 {
  cout<<"\n\t\tMENU\n"
      <<"\n\t 1.insert\n"
       <<"\n\t 2.search\n"
       <<"\n\t3.exit\n";
  cin>>k;


   switch(k)
   {
    case 1:
             cout<<"\n\tEnter no of words u want to enter\n";
             cin>>i;
             while(j<i)
             {
               cout<<"\n\t\tEnter the word\n";
               cin>>ch;
               c.insert(ch);
               j++;
             }
             break;
    case 2:
             cout<<"\n\tEnter the word u want to search\n";
             cin>>ch;
             c.search(ch);
             break;
    case 3:
              cout<<"\n\tEXIT\n";
              break;
  }
 }while(k!=3);
 getch();
 return 0;
}
