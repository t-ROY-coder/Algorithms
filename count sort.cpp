#include<iostream>
using namespace std;
int main()
{
	int l,h,size;
	cout<<"Enter the range of array i.e lower and upper range\n";
	cin>>l>>h;
	cout<<"Enter the no.of elements\n";
	cin>>size;
	int r=(h-l)+1;
	int a[r]={0};
	cout<<"Enter the elements\n";
	int t;
	for(int i=0;i<size;i++)
		{
			cin>>t;
			a[t-l]++;
		}
	for(int i=0;i<r;i++)
		{
			while(a[i]--)
			cout<<i+l<<" ";
		}	
	return 0;	
}
