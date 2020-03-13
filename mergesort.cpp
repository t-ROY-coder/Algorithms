#include<iostream>
using namespace std;
void merge(int a[],int l,int m,int h)
{
	int s1=m-l+1,s2=h-m;
	int b[s1],c[s2];
	for(int i=0;i<s1;i++)
	{
		b[i]=a[l+i];
	}
	for(int i=0;i<s2;i++)
	{
		c[i]=a[m+1+i];
	}
	int i=0,j=0,k=l;
	while(i!=s1 && j!=s2)
	{
		if(b[i]>=c[j])
			{
				a[k++]=c[j++];
			}
		else
			a[k++]=b[i++];	
	}
	if(i==s1)
	{
		while(j!=s2)
			a[k++]=c[j++];	
	}
	else if(j==s2)
			while(i!=s1)
				a[k++]=b[i++];		
}
void mergesort(int a[],int low,int high)
{
	if(low<high)
	{
		int middle=(high+low)/2;
		mergesort(a,low,middle);
		mergesort(a,middle+1,high);
		merge(a,low,middle,high);
	}

}
int main()
{
	int a[100];
	int size;
	cout<<"Enter the size of array\n";
	cin>>size;
	cout<<"Enter the elements in the array\n";
	for(int i=0;i<size;i++)
		cin>>a[i];
	int low=0,high=size-1;	
	mergesort(a,low,high);	
	for(int i=0;i<size;i++)
		cout<<a[i]<<" ";	
}
