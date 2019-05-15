// find the max points on same line
// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;

// handle overlapping points, for a particular point i add overlapping points to max slope
// find max among slope and vertical points

int main()
{
	int n;
	cin>>n;
	vector<pair<int,int> > point;
	for(int i=0;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		point.push_back({x,y});
	}
	map<pair<int,int>,int> m;
	int olp = 0;
	int inf = 0;
	int max_points = 0;
	for(int i=0;i<n;i++)
	{
		int cur_max = 0;
		for(int j=i+1;j<n;j++)
		{
			int num = point[i].second - point[j].second;
			int den = point[i].first - point[j].first;
			int g = __gcd(num,den);
			num = num/g;
			den = den/g;
			if(num == 0 && den == 0)
			{
				olp++;
			} 
			else if(num!=0 && den==0)
			{
				inf++;
			}
			else
			{
				m[{num,den}]++;
				cur_max = max(cur_max,m[{num,den}]);
			}
			cur_max = max(cur_max,inf);
			
		}
		max_points = max(max_points,cur_max + olp + 1);
		m.clear();
	}
	cout<<max_points<<endl;
}