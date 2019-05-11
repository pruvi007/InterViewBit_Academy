#include<bits/stdc++.h>
using namespace std;


vector<vector<int> > v;
void subset_sum(vector<int> &a,int n,int B)
{
	vector<int> temp;
	set<string> ss;
	int size = pow(2,n);
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<n;j++)
		{
			// to check if jth bit is set in i or not (if set then take else dont take)
			int x = i & (1<<j);
			// cout<<x;
			if(x)
			{
				temp.push_back(a[j]);
			}
		}
		// cout<<endl;
		int sum = 0;
		sort(temp.begin(),temp.end());
		for(int j=0;j<temp.size();j++)
		{
		  //  cout<<temp[j]<<" ";
		  sum += temp[j];
		}
		if(sum == B)
		{
			string st_temp = "";
			for(int j=0;j<temp.size();j++)
			{
				st_temp = st_temp + to_string(temp[j]) +'|';
			}
			if(ss.find(st_temp)==ss.end())
			{
				v.push_back(temp);
				ss.insert(st_temp);
			}
		}
		    
		
		temp.clear();
	}
}

vector<vector<int> > combinationSum(vector<int> &A, int B) {
    v.clear();
    subset_sum(A,A.size(),B);
    sort(v.begin(),v.end());
    return v;
}

int main()
{
	int n;
	cin>>n;
	vector<int> a;
	set<int> s;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		a.push_back(x);
		
	}
	

	int b;
	cin>>b;
	vector<vector<int> > ans;
	ans = combinationSum(a,b);
	for(int i=0;i<ans.size();i++)
	{
		for(int j=0;j<ans[i].size();j++)
			cout<<ans[i][j]<<" ";
		cout<<endl;
	}
}