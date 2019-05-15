/* to find the longest continous sequence with sum = 0 */
/* the idea is to find the longest distance of the same element appearing in prefix sum */
// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	map<ll,ll> m;
	ll sum = 0;
	m[0]=-1;
	int ans= INT_MIN;
	vector<int> ls;
	for(int i=0;i<n;i++)
	{
		sum += a[i];

		// dont update the already created map, just update the ans.
		if(m.find(sum)!=m.end())
		{
			int d = abs(m[sum] - i);
			if(d>ans)
			{
				ls.clear();
				ans = d;
				for(int j=m[sum]+1;j<=i;j++)
					ls.push_back(a[j]);
			}

		}
		else
		{
			m[sum] = i;
		}
	}
	cout<<ans<<endl;
	for(int i=0;i<ls.size();i++)
		cout<<ls[i]<<" ";
	cout<<endl;
}