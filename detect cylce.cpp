#include<bits/stdc++.h>
#include<queue>
#include<stack>
#include<stdlib.h>
using namespace std;
# define n 10

void addedge(int a[n][n],int i,int j)
{
	a[i][j]=1;
	return;
}
bool DFS(int a[n][n],int visited[n],int t,int parent)
{
	if(visited[t]==0)
	{
		visited[t]=1;
		for(int i=0;i<n;i++)
		{
			if(a[t][i]==1)
			{
				if(visited[i]==0 )
					{
						if(DFS(a,visited,i,t))
							return true;
					}
				else if(i!=parent)
					{
						return true;
					}
			}
		}
	}
	return false;
}
bool iscycle(int a[n][n],int visited[n],int recur[n])
{
	
	for(int j=0;j<n;j++)
	{
		recur[j]=0;
		visited[j]=0;
	}
	for(int i=0;i<n;i++)
	{
		if(visited[i]==0)
	if(DFS(a,visited,i,-1))
		{
			return true;
		}
	}
	return false;
}
int main()
{
	cout<<"Enter the no.of vertices in graph\n";
	int a[n][n];
	memset(a,0,n*n*sizeof(a[0][0]));
	for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				cout<<a[i][j]<<" ";
			cout<<endl;	
		}
	addedge(a,0,4);
	addedge(a,0,2);
	addedge(a,0,1);
	addedge(a,1,3);
	//addedge(a,1,4);
	addedge(a,1,1);
	addedge(a,2,7);
	//addedge(a,2,0);
	addedge(a,3,5);
	addedge(a,3,8);
	addedge(a,4,2);
	addedge(a,5,9);
	addedge(a,7,6);		
	cout<<endl;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<a[i][j]<<" ";
		cout<<endl;	
	}
	cout<<endl;
	int start=0;
	int visited[n];
	int recur[n];
	int count=0;
	memset(visited,0,sizeof(visited));
	if(iscycle(a,visited,recur))
		cout<<"Cycle is there\n";
	else
		cout<<"Cycle is not there\n";
	return 0;	
}
