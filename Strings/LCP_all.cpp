// find LCP on n given strings
// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<string> s;
	int minl= INT_MAX;
	int ind=-1;
	for(int i=0;i<n;i++)
	{
		string x;
		cin>>x;
		s.push_back(x);
		if(x.length()<minl)
		{
			minl = x.length();
			ind = i;
		}
	}

	int low = 0,high = s[ind].length()-1;
	string ans = "";
	while(low<=high)
	{
		int mid = (low+high)/2;
		string temp = s[ind].substr(0,mid+1);

		int valid=0;
		for(int i=0;i<n;i++)
		{
			string comp = s[i].substr(0,mid+1);
			if(comp!=temp)
			{
				valid=1;
				break;
			}
		}

		if(valid == 0)
		{
			ans = temp;
			low = mid+1;
		}
		else high = mid-1;
	}
	cout<<ans<<endl;

}