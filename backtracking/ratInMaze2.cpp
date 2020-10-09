/*
    handle - pruvi007
    questionName - 
    Contest - 
    Topic - 
    Platform - 
*/
#include<bits/stdc++.h>
using namespace std;
#define ll          long long int
#define fast         ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define INF          1e18
#define MOD          1000000007
#define Vi           vector<ll> 
#define Vs           vector<string>
#define VI           vector<vector<ll> >
#define PII          pair<ll,ll> 
#define PSI          pair<string,ll>
#define PB           push_back


int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};
int DX[] = {0,-1,-1,-1,0,1,1,1};
int DY[] = {-1,-1,0,1,1,1,0,-1};
int a[6][6];
bool vis[6][6];
char ch[] = {'D','U','L','R'};

bool safe(int x,int y,int n)
{
	return x>=0 and x<n and y>=0 and y<n and a[x][y]!=0;
}
void solve(int x,int y,int n, string s)
{
	if(x<0 or y<0 or x>=n or y>=n)
		return ;
	if( x==n-1 and y==n-1)
	{
		cout << s << '\n';
		return;
	}
	// set this to true
	vis[x][y] = true;
	for(int i=0;i<4;i++)
	{
		int nx = x+dx[i];
		int ny = y+dy[i];
		if( safe( nx,ny,n ) and vis[nx][ny]==false )
			solve(nx,ny,n,s+ch[i]);
	}
	// backtrack
	vis[x][y] = false;

}
int main()
{
    fast;
    int n;
    cin >> n;

    memset(vis,false,sizeof(vis));

    for(int i=0;i<n;i++)
    	for(int j=0;j<n;j++)
    		cin >> a[i][j];
    if(a[0][0]==0 or a[n-1][n-1]==0)
    	cout << "NO" << '\n';
    else
    	solve(0,0,n,"");
}