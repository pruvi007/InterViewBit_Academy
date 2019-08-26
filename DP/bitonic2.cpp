/*
	BITONIC SEQ.
	find the longest subsequnce which is first increasing then decreasing
	idea: calculate LIS and LDS and then max of lis[i]+lds[j] will be the answer
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    		cin>>a[i];
    	int lis[n];
    	lis[0]=1;
    	int s1[n]={0};
        int s2[n]={0};
        for(int i=0;i<n;i++)
        {
            s1[i] = s2[i] = a[i];
        }
    	for(int i=1;i<n;i++)
    	{
    		lis[i] = 1;
    		s1[i] = a[i];
    		for(int j=0;j<i;j++)
    		{
    			if(a[i] > a[j])
    			{
                    if( lis[i] < lis[j]+1 )
                    {
                        lis[i] = lis[j]+1;
                        s1[i] += a[j];
                    }
    				
    			}
    		}
            
    	}
        cout << endl;
        for(int j=0;j<n;j++)
            cout << s1[j] << " ";
        cout << endl;
        
        
    	int lds[n];
    	lds[n-1] = 1;
    	for(int i=n-2;i>=0;i--)
    	{
    		lds[i]=1;
    		s2[i] = a[i];
    		for(int j=n-1;j>i;j--)
    		{
    			if(a[i] > a[j])
    			{
                    if( lds[i] < lds[j]+1 )
                    {
                        lds[i] = lds[j]+1;
                        s2[i] += a[j];
                    }
    				
    			}
    		}
            
    	}
        for(int j=0;j<n;j++)
            cout << s2[j] << " ";
        cout << endl;
    	int max = 0;
    	int f = 0;
        
    	for(int i=0;i<n;i++)
    	{

    		int x = s1[i] + s2[i];
    		if(x>max)
    		{
                max = x-a[i];
    		      

    		    // f = s1[i] + s2[i];
    		}
    			
    	}
    	cout << max << endl;
    }
	
}