/*
	Implement a MIN HEAP
	build,insert, delete,get_min
	insert->bottom up
	delete->top-down
*/
// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;

int heap[100];
int ch = 0;

void insert(int x)
{
	if(ch == 0)
		heap[ch++] = x;
	else
	{
		// insert child at the last (as the new child) (new child because heaps are complete binary tree)
		heap[ch++] = x;
		for(int i=ch-1;i>=0;i--)
		{
			int child = i;
			while(1)
			{
				// consider parent of each child and comapre whether its min or not.
				int p = (child-1)/2;
				if(p<0)
					break;
				if(heap[p]>heap[child])
				{
					int temp = heap[p];
					heap[p] = heap[child];
					heap[child] = temp;
				}
				else break;
				// jump to parent and make it the child
				child = p;
			}

		}
	}
}

int getMin()
{
	return heap[0];
}
void deleteMin()
{
	// copy the last element to the first
	heap[0] = heap[ch-1];
	// reduce the size to delete the min element
	ch--;

	// do top-down heapify
	for(int i=0;i<ch;i++)
	{

		// compare parent with children
		int p = i;
		int c1 = 2*i+1;
		int c2 = 2*i+2;

		// if smaller child exist then swap with the smaller child
		if(c1<ch && c2<ch && heap[c1]<heap[c2] && heap[p]>heap[c1])
		{
			int temp = heap[p];
			heap[p] = heap[c1];
			heap[c1] = temp;
		}
		else if(c1<ch && c2<ch && heap[c2]<=heap[c1] && heap[p]>heap[c2])
		{
			int temp = heap[p];
			heap[p] = heap[c2];
			heap[c2] = temp;
		}
		
	}
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		insert(a[i]);
	}
	for(int i=0;i<ch;i++)
		cout<<heap[i]<<" ";
	cout<<endl;
	cout<<getMin()<<endl;
	deleteMin();
	deleteMin();
	for(int i=0;i<ch;i++)
		cout<<heap[i]<<" ";
	cout<<endl;

}