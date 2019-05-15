/*
	Given an array A of integers, find the index of values that satisfy A + B = C + D, where A,B,C & D are integers values in the array Note:
	1) Return the indices `A1 B1 C1 D1`, so that 
	  A[A1] + A[B1] = A[C1] + A[D1]
	  A1 < B1, C1 < D1
	  A1 < C1, B1 != D1, B1 != C1 

	2) If there are more than one solutions, 
	   then return the tuple of values which are lexicographical smallest. 

	Assume we have two solutions
	S1 : A1 B1 C1 D1 ( these are values of indices int the array )  
	S2 : A2 B2 C2 D2

	S1 is lexicographically smaller than S2 iff
	  A1 < A2 OR
	  A1 = A2 AND B1 < B2 OR
	  A1 = A2 AND B1 = B2 AND C1 < C2 OR 
	  A1 = A2 AND B1 = B2 AND C1 = C2 AND D1 < D2
	Example:
	Input: [3, 4, 7, 1, 2, 9, 8]
	Output: [0, 2, 3, 5] (O index)
	If no solution is possible, return an empty list.

*/

// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	map<int,vector<pair<int,int>> > m;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			int d = a[i]+a[j];
			m[d].push_back({i,j});
		}
	}
	
	map<int,vector<pair<int,int>> >::iterator it;
	vector<vector<pair<int,int> > > v;
	for(it=m.begin();it!=m.end();it++)
	{
		vector<pair<int,int> > temp = it->second;
		cout<<(it->first)<<" : ";
		for(int i=0;i<temp.size();i++)
			cout<<" "<<temp[i].first<<" "<<temp[i].second;
		cout<<endl;
		v.push_back(temp);
	}
	cout<<endl;
	sort(v.begin(), v.end());

	vector<int> ans;
	for(int i=0;i<v.size();i++)
	{
		if(v[i].size()>=2)
		{
			
			for(int j=0;j<2;j++)
			{
			    ans.push_back(v[i][j].first);
			    ans.push_back(v[i][j].second);
			    cout<<" "<<v[i][j].first<<" "<<v[i][j].second<<"" ;
			}
			int valid = (ans[0]<ans[2]) && (ans[1]!=ans[2]) && (ans[1]!=ans[3]);
			cout<<":"<<valid<<endl;
		}
		
	}
}