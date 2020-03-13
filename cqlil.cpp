#include<iostream>
#include<conio.h>
#define SIZE 100

using namespace std;

struct cq
{
  int data;
  struct cq *next;
}*f=NULL,*r=NULL,*n,*temp,*temp1;

void cq_ins();
void cq_del();
void cq_peep();
void cq_chg();
void cq_dis();

int main()
{
  int ch;
  do
  {
     cout<<"\n\n\tMain Menu";
     cout<<"\n##########################";
     cout<<"\n1. Insert\n2. Delete\n3. Display\n4. Search\n5. Change\n6. Exit\n\nEnter Your Choice: ";
     cin>>ch;
     switch(ch)
     {
        case 1:
          cq_ins();
          cq_dis();
          break;
        case 2:
          cq_del();
          break;
        case 3:
          cq_dis();
          break;
        case 4:
          cq_peep();
          break;
        case 5:
          cq_chg();
          break;
        case 6:
          break;
        default:
          cout<<"\n\nWrong Choice!!! Try Again.";
     }
  }while(ch!=6);
  return 0;
  getch();
}

void cq_ins()
{
  n=new cq[sizeof(cq)];
  cout<<"\nEnter the Element: ";
  cin>>n->data;
  if(f==NULL)
  {
      f=n;
  }
  else
  {
      r->next=n;
  }
  r=n;
  r->next=f;
}

void cq_del()
{
  int x;
  temp=f;
  if(f==NULL)
  {
      cout<<"\nCircular Queue Empty!!!";
  }
  else
  {
     if(f==r)
     {
       x=f->data;
       delete(temp);
       f=NULL;
       r=NULL;
     }
     else
     {
        x=temp->data;
        f=f->next;
        r->next=f;
        delete(temp);
     }
     cout<<"\nElement "<<x<<" is Deleted";
     cq_dis();
  }
}

void cq_peep()
{
  int c=1,pos;
  temp=f;
  temp1=NULL;
  cout<<"\nEnter the Position: ";
  cin>>pos;
  if(f==NULL)
  {
      cout<<"\nCircular Queue is Empty";
  }
  else
  {
     while(temp!=temp1)
     {
        if(c==pos)
        {
            cout<<"\nThe Element at Position "<<pos<<" is "<<temp->data;
            break;
        }
        temp=temp->next;
        temp1=f;
        c++;
     }
     cq_dis();
  }
}

void cq_chg()
{
  int c=1,pos,ne;
  temp=f;
  temp1=NULL;
  cout<<"\nEnter the Position of the Element: ";
  cin>>pos;
  cout<<"\nEnter the New Value: ";
  cin>>ne;
  if(f==NULL)
  {
        cout<<"\nCircular Queue Empty!!!";
  }
  else
  {
     while(temp!=temp1)
     {
        if(c==pos)
        {
           temp->data=ne;
           break;
        }
        temp=temp->next;
        temp1=f;
        c++;
     }
     cq_dis();
  }
}

void cq_dis()
{
  temp=f;
  temp1=NULL;
  if(f==NULL)
  {
    cout<<"\n\nCircular Queue Empty!!!";
  }
  else
  {
    cout<<"\n\nCircular Queue Elements are:\n\n";
    while(temp!=temp1)
    {
       cout<<temp->data<<"  ";
       temp=temp->next;
       temp1=f;
    }
  }
}
