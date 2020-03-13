#include<bits/stdc++.h>
#include<queue>
#include<stack>
#include<stdlib.h>
using namespace std;
# define n 12
void addedge(int a[n][n],int i,int j)
{
	a[i][j]=1;
	return;
}
void DFS(int a[n][n],int visited[n],int start,int &count)
{
	stack<int>s;
	s.push(start);
	while(!s.empty())
	{
		int flag=1;
		int t=s.top();
		if(visited[t]==0)
		{
			cout<<t<<" ";
			count++;
			visited[t]=1;	
		}
		for(int i=0;i<n;i++)
		{
			if(a[t][i]==1 && visited[i]==0)
			{
				flag=1;
				s.push(i);
				break;
			}
			else
			{
				flag=0;
			}
		}
		if(flag==0)
			s.pop();
	}
	if(count!=n)
	{
		for(int i=0;i<n;i++)
		{
			if(visited[i]==0)
				{
					start=i;
					break;
				}
		}
		DFS(a,visited,start,count);
	}
	else
		return ;
}
void BFS(int a[n][n],int visited[n],int start,int &count)
{
	queue<int>q;
	q.push(start);
	visited[start]=1;
		while(!q.empty())
		{
			int t=q.front();
			cout<<t<<" ";
			q.pop();
			count++;
			for(int i=0;i<n;i++)
			{
				if(visited[i]==0 && a[t][i]==1)
					{
						q.push(i);
						visited[i]=1;
					}
			}
		}
		if(count!=n)
		{
			for(int i=0;i<n;i++)
				{
					if(visited[i]!=1)
					{
						start=i;
						break;
					}
				}
			BFS(a,visited,start,count);
		}
		else
			return;
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
	addedge(a,1,4);
	addedge(a,1,1);
	addedge(a,2,7);
	addedge(a,3,5);
	addedge(a,3,8);
	addedge(a,4,2);
	addedge(a,5,9);
	addedge(a,7,6);
	addedge(a,10,9);
	addedge(a,10,6);
	addedge(a,11,6);		
	cout<<endl;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<a[i][j]<<" ";
		cout<<endl;	
	}
	cout<<endl;
	int start=1;
	int visited[n];
	int count=0;
	memset(visited,0,sizeof(visited));
	BFS(a,visited,start,count);
	cout<<endl;
	start=0,count=0;
	memset(visited,0,sizeof(visited));
	DFS(a,visited,start,count);
	return 0;	
}
