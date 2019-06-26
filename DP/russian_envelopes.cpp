/*
	Russian Doll Envelopes
	Find the max number of envelopes that can be fit on to one another
	idea: sort them according to area and apply LIS
	NOTE: You can flip envelopes (so now generate both the configurations)
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;

struct myComp
{
	bool operator()(pair<int,int> a,pair<int,int> b)
	{
		int a1 = a.first * a.second;
		int a2 = b.first * b.second;
		return a1 < a2;
	}
};
int main()
{
	int n;
	cin >> n;
	vector<pair<int,int> > v;
	for(int i=0;i<n;i++)
	{
		int x,y;
		cin >> x >> y;
		v.push_back({x,y});
	}
	sort(v.begin(),v.end(),myComp());
	for(int i=0;i<n;i++)
	{
		int a = v[i].first * v[i].second;
		cout << v[i].first << " " << v[i].second << " " << a << endl ;
	}

	int LIS[n];
	LIS[0]=1;
	for(int i=1;i<n;i++)
	{
		LIS[i]=1;
		for(int j=0;j<i;j++)
		{
			if(v[j].first<v[i].first && v[j].second<v[i].second)
			{
				LIS[i] = max(LIS[i],1+LIS[j]);
			}
		}
	}
	cout << *max_element(LIS,LIS+n) << endl;

}
// the above implementation runs in O(n*n)
// however we can do it nlgn

// following is that function
/*
	vector<pair<int,int> > l;
    l.push_back(v[n-1]);
    for(int i=n-2;i>=0;i--)
    {
        int low=0,high=l.size()-1;
        while(low <= high)
        {
            int mid = (low+high)/2;
            if(l[mid].second<= v[i].second)
            {
                high = mid-1;
            }
            else
                low = mid+1;
        }
        // if reached the end of array then add it to the list
        if(low == l.size())
        {
            l.push_back(v[i]);
        }
        // replace the list element
        else
        {
            l[low].first = v[i].first;
            l[low].second = v[i].second;
        }
    }
    return l.size();
*/