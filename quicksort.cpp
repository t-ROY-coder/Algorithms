#include<iostream>
using namespace std;
void swap(int &k1,int &k2)
{
	int temp=k1;
	k1=k2;
	k2=temp;
	return;
}
int partition(int a[],int l,int h)
{
	
	int pivot=l++;
	while(l<h)
	{
		while(a[pivot]>a[l] )
			l++;
		while(a[pivot]<a[h] )
			h--;	
		if(l<h)
			{
				swap(a[l],a[h]);
			}
	}
	swap(a[pivot],a[h]);
	return h;
}
void quicksort(int a[],int l,int h)
{
	if(l<h)
	{
	int pivot=partition(a,l,h);
	quicksort(a,l,pivot-1);
	quicksort(a,pivot+1,h);
	}
	
}
int main()
{
	int size;
	cout<<"Enter the size\n";
	cin>>size;
	cout<<"enter the elements\n";
	int a[size];
	for(int i=0;i<size;i++)
		cin>>a[i];
	int l=0;
	int h=size-1;	
	quicksort(a,l,h);	
	for(int i=0;i<size;i++)
		cout<<a[i]<<" ";
}
