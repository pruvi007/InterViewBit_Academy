#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll mod = 1e9+7;

int getPar(int x,int par[]){
    while(x!=par[x])
        x = par[x];
    return x;
}
int find(int x,int y,int par[])
{
    return getPar(x,par) == getPar(y,par);
}
int doUnion(int x,int y,int par[],int size[])
{
    if( find(x,y,par) )
        return -1;
    int p1 = getPar(x,par);
    int p2 = getPar(y,par);
    int s1 = size[p1];
    int s2 = size[p2];
    if( s1 > s2 )
    {
        par[p2] = p1;
        size[p1] += s2;
    }
    else
    {
        par[p1] = p2;
        size[p2] += s1;
    }
    return 1;
}

ll power( ll a, ll b)
{
	ll res = 1;
	while(b)
	{
		if(b%2)
			res = (res%mod * a%mod)%mod;
		a = (a%mod * a%mod)%mod;
		b = b/2;
	}
	return res%mod;
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,m;
		cin >> n >> m;

		// init DSU
	    int par[n+1],size[n+1];
	    for(int i=1;i<=n;i++)
	    {
	        par[i] = i;
	        size[i] = 1;
	    }
	    int dis = n;
	    int safe = 0;
	    for(int i=0;i<m;i++)
	    {
	    	int x,y;
	    	cin >> x >> y;

	    	int b = doUnion(x,y,par,size);
	    	if( i== 0 and b==1)
	    	{
	    		dis -= 2; 
	    		safe++;
	    	}
	    	else if( i>0 and b==1)
	    	{
	    		dis-=1;
	    		safe++;
	    	}
	    	// cout << power(safe,dis) << " ";

	    }
	    int q;
	    cin >> q;
	    while(q--)
	    {
	    	int x,y;
	    	cin >> x >> y;

	    	int b = doUnion(x,y,par,size);
	    	if( safe==0 and b==1)
	    	{
	    		dis -= 2; 
	    		safe++;
	    	}
	    	else if( safe>0 and b==1)
	    	{
	    		dis-=1;
	    		safe++;
	    	}
	    	// cout << safe << " " << dis << endl;
	    	cout << power(safe,dis) << " ";
	    }
	    cout << endl;

	}
}