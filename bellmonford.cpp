#include<iostream.h>
#include<stdlib.h>

#define MAX 20
#define INFINITY 9999

class bell_ford
{
private:
 int n;
 int graph[MAX][MAX];
 int start;
 int distance[MAX];
 int predecessor[MAX];
public:
 void read_graph();
 void initialize();
 void update();
 void check();
 void algorithm();
};

void bell_ford::read_graph()
{
 cout<<”Enter the no. of nodes in the graph ::”;
 cin>>n;
 cout<<”Enter the adjacency matrix for the graph ::\n”;
 for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++)
   cin>>graph[i][j];
 cout<<”Enter the start vertex ::”;
 cin>>start;
}

void bell_ford::initialize()
{
 for(int i=1;i<=n;i++)
 {
   distance[i]=INFINITY;
   predecessor[i]=0;
 }
 distance[start]=0;
}

void bell_ford::update()
{
 for(int i=1;i<=n-1;i++)
 {
  for(int u=1;u<=n;u++)
  {
   for(int v=1;v<=n;v++)
   {
    if(graph[u][v]!=0)
    {
     if(distance[v]>distance[u]+graph[u][v])
     {
      distance[v]=distance[u]+graph[u][v];
      predecessor[v]=u;
     }
    }
   }
  }
 }
}

void bell_ford::check()
{
 for(int u=1;u<=n;u++)
 {
  for(int v=1;v<=n;v++)
  {
   if(graph[u][v]!=0)
   {
    if(distance[v]>distance[u]+graph[u][v])
    {
     cout<<”does not exist’s “;
     return;
    }
   }
  }
 }

 cout<<”\n\nThere is no negative weight cycle and\n”;
 cout<<”****** The final paths and the distacnes are ******\n\n”;
 for(int i=1;i<=n;i++)
 {
  cout<<”path for node “<<i<<” is ::\n”;
  int arr[MAX],k=1;
  int j=i;
  while(predecessor[j]!=0)
  {
   arr[k]=predecessor[j];
   k++;
   j=predecessor[j];
  }
  for(–k;k>0;k–)
   cout<<arr[k]<<”->”;
  cout<<i<<endl;
  cout<<”distance is “<<distance[i]<<endl<<endl<<endl;
 }
}

void bell_ford::algorithm()
{
 read_graph();
 initialize();
 update();
 check();
}

void main()
{
 bell_ford obj;
 obj.algorithm();
}
