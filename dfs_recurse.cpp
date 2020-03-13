#include <iostream>
using namespace std;

int adj[10][10];
int visited[10]={0},v;

void dfsrec(int n)
{
    visited[n]=1;
    cout<<n<<" ";
    for(int i=0;i<v;i++)
    {
        if(visited[i]!=1 && adj[n][i]==1)
        {
            dfsrec(i);
        }
    }
}

int main()
{
    int i,j,start;
    cout<<"Enter the no. of vertices : ";
    cin>>v;
    cout<<"Enter the adj vertices :\n";
    while(i!=j)
    {
        cin>>i>>j;
        if(i!=j)
        {
            adj[i][j]=1;
            adj[j][i]=1;
        }

    }
    cout<<"Enter the starting vertex : ";
    cin>>start;
    dfsrec(start);
    return 0;
}
