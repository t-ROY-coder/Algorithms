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
void DFS(int a[n][n],int visited[n],int start)
{
	string str;
	stack<int>s;
	s.push(start);
	visited[start]=1;
	char c='0'+start;
	str.push_back(c);
	str.push_back(' ');
	while(!s.empty())
	{
		int flag=1;
		int t=s.top();
		if(a[t][start]==1)
			{
				c='0'+start;
				str.push_back(c);
				break;
			}
		else
		{		
			for(int i=0;i<n;i++)
			{
				if(a[t][i]==1 && visited[i]==0)
				{
					flag=1;
					s.push(i);
					c='0'+i;
					str.push_back(c);
					str.push_back(' ');
					visited[i]=1;
					break;
				}
				else
				{
					flag=0;
				}
			}
			if(flag==0)
				{
				str.erase(str.begin()+str.size()-1);
				str.erase(str.begin()+str.size()-1);
				s.pop();
				}		
		}
	}
	if(str.size()!=0)
	cout<<str<<endl;
}
void iscycle(int a[n][n],int visited[n])
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		visited[j]=0;
	DFS(a,visited,i);
	}
	return ;
	
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
	addedge(a,2,0);
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
	int count=0;
	memset(visited,0,sizeof(visited));
	iscycle(a,visited);
	return 0;	
}
