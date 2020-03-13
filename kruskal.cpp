#include<bits/stdc++.h>
#include<queue>
#include<stack>
#include<stdlib.h>
using namespace std;
# define n 7
struct edge
{
	int v1,v2,w;
};
int ne=9;
struct edge E[9];
void swap(struct edge &e1,struct edge &e2 )
{
	int temp;
	temp=e2.v1;
	e2.v1=e1.v1;
	e1.v1=temp;
	
	temp=e2.v2;
	e2.v2=e1.v2;
	e1.v2=temp;
	
	temp=e2.w;
	e2.w=e1.w;
	e1.w=temp;
}
bool DFS(int a[n][n],int visited[n],int t,int parent)
{
	if(visited[t]==0)
	{
		visited[t]=1;
		for(int i=0;i<n;i++)
		{
			if(a[t][i]!=0)
			{
				if(visited[i]==0)
					{
						if(DFS(a,visited,i,t))
						return true;
					}
				else if(i!=parent)
					{
						return true;
					}
			}
			else
				continue;
		}
	}
	return false;
}
bool iscycle(int a[n][n],int visited[n])
{
	
	for(int j=0;j<n;j++)
	{
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
void Bubblesort(struct edge E[9])
{
	for(int i=0;i<ne-1;i++)
	{
		for(int j=1;j<ne;j++)
		{
			if((E[j].w)<(E[j-1].w))
				swap(E[j],E[j-1]);
		}
	}
}
void addedge(int a[n][n],int i,int j,int weight,int &count)
{
	a[i][j]=weight;
	E[count].w=weight;
	E[count].v1=i;
	E[count].v2=j;
	count++;
	return;
}
void minspantree(int a[n][n],int mst[n][n],int visited[n],struct edge E[9])
{
	Bubblesort(E);
	memset(mst,0,n*n*sizeof(mst[0][0]));
	for(int k=0;k<9;k++)
	{
		memset(visited,0,n*n*sizeof(visited[0]));
		mst[E[k].v1][E[k].v2]=E[k].w;
		mst[E[k].v2][E[k].v1]=E[k].w;
		if(iscycle(mst,visited))
				{
					mst[E[k].v1][E[k].v2]=0;
					mst[E[k].v2][E[k].v1]=0;
				}
		else
			continue;	
	}
}
int main()
{
	int a[n][n];
	int mst[n][n];
	int visited[n];
	memset(a,0,n*n*sizeof(a[0][0]));
	for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				cout<<a[i][j]<<" ";
			cout<<endl;	
		}
		int count=0;
	addedge(a,0,5,10,count);
	addedge(a,0,1,28,count);
	addedge(a,1,2,16,count);
	addedge(a,1,6,14,count);
	addedge(a,6,3,18,count);
	addedge(a,2,3,12,count);
	addedge(a,3,4,22,count);
	addedge(a,4,5,25,count);
	addedge(a,4,6,24,count);			
	cout<<endl;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<a[i][j]<<" ";
		cout<<endl;	
	}
	///
	cout<<endl;

	cout<<endl;
	minspantree(a,mst,visited,E);
	cout<<"Minimumspanningtree\n";
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				cout<<mst[i][j]<<" ";
			cout<<endl;
			cout<<"y";	
		}
		cout<<"m";
	return 0;
}
