
/*
    handle - pruvi007
    questionName - SnakeLadders
    Contest - NA
    Topic - Graphs
    Platform - HR
*/
#include<bits/stdc++.h>
using namespace std;
#define ll          long long int
#define fast         ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define INF          1e18
#define Vi           vector<int> 
#define VI           vector<vector<int> >
#define VL           vector<vector<long long int> > 
#define PII          pair<int,int> 
#define PLL          pair<long long int,long long int>
#define PSI          pair<string,int>
#define PB           push_back

int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};
int DX[] = {0,-1,-1,-1,0,1,1,1};
int DY[] = {-1,-1,0,1,1,1,0,-1};

int isProp(int nx,vector<PII>&v){
	for(int i=0;i<v.size();i++)
	{
		if(v[i].first==nx)
			return v[i].second;
	}
	return 0;
}

int main()
{
    fast;
    int t;
    cin >> t;
    while(t--){
    	int n;
    	cin >> n;
    	vector<PII> ladder,snake;
    	for(int i=0;i<n;i++)
    	{
    		int x,y;
    		cin >> x >> y;
    		ladder.PB({x,y});
    	}
    	int m;
    	cin >> m;
    	for(int i=0;i<m;i++)
    	{
    		int x,y;
    		cin >> x >> y;
    		snake.PB({x,y});
    	}
    	queue<PII> q;
    	q.push({1,0});
    	set<int> vis;
    	int ans = INT_MAX;
    	while(!q.empty())
    	{
    		PII p = q.front();
    		q.pop();
    		vis.insert(p.first);
			
    		if(p.first==100)
    		{
    			ans = min(ans,p.second);
    		}
    		// cout << p.first << ": ";
    		for(int i=1;i<=6;i++)
    		{
    			int nx = p.first + i;
				// cout << "(" << nx<<"," ; 
    			if(isProp(nx,snake))
    				nx = isProp(nx,snake);
				if(isProp(nx,ladder))
					nx = isProp(nx,ladder);
				// cout << nx << ") " ;
    			if(nx<=100 and vis.find(nx)==vis.end())
    			{
    				q.push({nx,p.second+1});
    				vis.insert(nx);
    			}
    				
    		}
			// cout << endl;
    	}
		if(ans==INT_MAX)
			ans = -1;
    	cout << ans << '\n';
    }
}
