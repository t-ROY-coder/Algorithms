#include <iostream>
#include <stack>
using namespace std;
int adj[10][10];
int visited[10]={0},v;
stack<int> s;
void DFS(int start)
{
    //stack<int> s;
    int f=0,i=0,c=0;
    visited[start]=1;
    s.push(start);
    cout<<start<<" ";
    if(s.empty())
        return;
    /*for(int k=0;k<v;k++)
    {
        c+=visited[i];
    }
    if(c==v)
        return;8*/
    //int a=adj[start][i];
    for(i=0;i<v;i++)
    {
        int a=adj[start][i];
        if(a==1 && visited[i]==0)
        {
            f=1;
            break;
        }
    }
    if(f==1)
        DFS(i);
    else
    {
        f=0;
        int x;
        while(f!=1)
        {
            s.pop();
            x=s.top();
            for(i=0;i<v;i++)
            {
                int a=adj[x][i];
                if(a==1 && visited[i]==0)
                {
                    f=1;
                    break;
                }
            }
        }
        DFS(i);
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
    DFS(start);
    return 0;
}
