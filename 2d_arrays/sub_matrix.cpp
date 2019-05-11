#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int a[n][m];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>a[i][j];
		}
	}

	for(int i=0;i<n;i++)
	{
		for(int j=1;j<m;j++)
		{
			a[j][i] = a[j][i] + a[j-1][i];
		}
	}

	// for(int i=0;i<n;i++)
	// {
	// 	for(int j=0;j<m;j++)
	// 	{
	// 		cout<<a[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }

	for(int i=0;i<n;i++)
	{
		for(int j=1;j<m;j++)
		{
			a[i][j] = a[i][j] + a[i][j-1];
		}
	}

	// for(int i=0;i<n;i++)
	// {
	// 	for(int j=0;j<m;j++)
	// 	{
	// 		cout<<a[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }

	int l = 2;
	vector<int> B,C,D,E;
	for(int i=0;i<l;i++)
	{
		int x;
		cin>>x;
		B.push_back(x);
	}
	for(int i=0;i<l;i++)
	{
		int x;
		cin>>x;
		C.push_back(x);
	}
	for(int i=0;i<l;i++)
	{
		int x;
		cin>>x;
		D.push_back(x);
	}
	for(int i=0;i<l;i++)
	{
		int x;
		cin>>x;
		E.push_back(x);
	}

	vector<int> res;
	
	for(int i=0;i<l;i++)
	{
	    int t1,t2,r1,r2;
	    t1 = B[i];
	    t2 = C[i];
	    r1 = D[i];
	    r2 = E[i];
	    int temp = a[r1-1][r2-1];
	    if(t1>1)
	        temp = temp - a[t1-2][r2-1];
	    if(t2>1)
	        temp = temp - a[r1-1][t2-2];
	    if(t1>1 && t2>1)
	        temp = temp + a[t1-2][t2-2];
	    
	    res.push_back(temp);
	    
	}
	for(int i=0;i<l;i++)
		cout<<res[i]<<" ";
	cout<<endl;


}