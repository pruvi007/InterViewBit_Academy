#include<bits/stdc++.h>
using namespace std;
#define ll long long int

map<ll,ll> mp;
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
        mp[p1] += s2;
        mp.erase(p2);
        size[p1] += s2;
    }
    else
    {
        par[p1] = p2;
        mp[p2] += s2;
        mp.erase(p1);
        size[p2] += s1;
    }
    return 1;
}

int main()
{
	int n,q;
	scanf("%d %d",&n,&q);

	// init DSU
    int par[n+1],size[n+1];
    for(int i=1;i<=n;i++)
    {
        par[i] = i;
        mp[i] = 1;
        size[i] = 1;
    }

    while(q--)
    {
    	int x,y;
    	cin >> x >> y;
    	int b = doUnion(x,y,par,size);
    	auto it2 = mp.begin();
    	advance(it2,1);
    	int m = INT_MAX;
    	for(auto itr = mp.begin();itr!=mp.end();itr++)
    		cout << itr->first << " " << itr->second << endl;
    	for(auto it1 = mp.begin();it1!=mp.end();it1++)
    	{
    		if(it2 == mp.end())
    			break;
    		int d = abs(it2->second - it1->second);
    		if( d<m )
    			m = d;
    		advance(it2,1);
    		
    	}
    	if(m==INT_MAX)
    		cout << 0 << endl;
    	else
    		cout << m << endl;
    }
}