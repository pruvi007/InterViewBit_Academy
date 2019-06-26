/*
	find the kth smallest element in a sorted matrix
	idea: push the smallest element and then pop and push the two contenders in a min heap.
*/
// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;

struct node{
    int val;
    int i;
    int j;
    node(int val,int i,int j)
    {
        this->val = val;
        this->i = i;
        this->j = j;
    }
};
struct myComp{
    int operator()(node& a,node& b)
    {
        return (a.val>b.val);
    }
};

int main()
{
	int n;
	cin>>n;
	int a[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cin>>a[i][j];
	}
	int k;
	cin>>k;

	
	priority_queue< node,vector<node>,myComp > pq,temp;
    pq.push(node(a[0][0],0,0));
    
    
    int flag[n][n];
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<n;j++)
    		flag[i][j]=0;
    }
    
    int c = 0;
    flag[0][0]=1;
    for(int z=0;z<k-1;z++)
    {
        node x = pq.top();
        
        int i = x.i;
        int j = x.j;
        
        pq.pop();
        // now push the two contenders
        if((j+1)<n && flag[i][j+1]==0)
        {
            pq.push(node(a[i][j+1],i,j+1));
            flag[i][j+1] = 1;
        }
            
        if((i+1)<n && flag[i+1][j]==0)
        {
            pq.push(node(a[i+1][j],i+1,j));
            flag[i+1][j]=1;
        }   
        temp = pq;
        // while(!temp.empty())
        // {
        // 	cout<<temp.top().val<<" ";
        // 	temp.pop();
        // }  
        cout<<endl;          
    }

    cout<<pq.top().val<<endl;
    cout<<endl;
    
        
        
    
}