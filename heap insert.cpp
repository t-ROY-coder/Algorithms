#include<iostream>
using namespace std;
struct heap{
	int array[1000];
	int size;
	int currentsize;
};
void swap(int &k1,int &k2)
{
	int temp=k1;
	k1=k2;
	k2=temp;
	return;
}
void percolatedown(heap &h,int i)
{	
	if(i==h.currentsize-1)
		return;
		
	int child=(h.array[2*i+1]>h.array[2*i+2])? (2*i+1) : (2*i+2); 
	if(!((2*i+1)>(h.currentsize-1)))
	{
		if(h.array[i]<h.array[2*i+1]||h.array[i]<h.array[2*i+2])
		{
			swap(h.array[child],h.array[i]);
			percolatedown(h,child);
		}
	}
}
void percolateup(heap &h,int i)
{
	int parent=(i-1)/2;
	if(h.array[parent]<h.array[i])
	{ 
		swap(h.array[parent],h.array[i]);
	}
	if(parent!=0)
	percolateup(h,parent);
}
void display(heap h)
{
	for(int i=0;i<h.currentsize;i++)
	{
		cout<<h.array[i]<<" ";
	}
	cout<<endl;
}
void insert(heap &h,int key)
{
	h.array[h.currentsize++]=key;
	int i=h.currentsize-1;
	percolateup(h,i);
	display(h);
}
void delete_element(heap &h,int key)
{
	int i=0; 
	while(h.array[i]!=key)
		i++;
	swap(h.array[i],h.array[h.currentsize-1]);	
	h.currentsize--;
	if(h.currentsize>=3)
	percolatedown(h,i);
	else if(h.currentsize==2)
		{
			swap(h.array[i],h.array[2*i+1]);
		}
}
int main()
{
	heap h;
	cout<<"Enter the size of maxheap\n";
	cin>>h.size;
	h.currentsize=0;
	insert(h,15);
	insert(h,3);
	insert(h,6);
	insert(h,20);
	insert(h,1);
	insert(h,5);
	insert(h,19);
	insert(h,70);
	insert(h,80);
	insert(h,17);
	cout<<endl;
	for(int i=0;i<=h.size;i++)
	{
		delete_element(h,h.array[0]);
		display(h);
	}
	return 0;
}
