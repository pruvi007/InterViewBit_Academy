/*
	Maintain the information of Max and Min along with the information of parents
	so that you can answer it in O(1)
	create M[], m[] and keep track of max and min for each group
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int


int getPar(int x,int par[]){
    while(x!=par[x])
        x = par[x];
    return x;
}
int find(int x,int y,int par[])
{
    return getPar(x,par) == getPar(y,par);
}
int doUnion(int x,int y,int par[],int size[],int m[],int M[])
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
        m[p1] = min(m[p2],m[p1]);
        M[p1] = max(M[p1],M[p2]);
        size[p1] += s2;
    }
    else
    {
        par[p1] = p2;
        m[p2] = min(m[p2],m[p1]);
        M[p2] = max(M[p1],M[p2]);
        size[p2] += s1;
    }
    return 1;
}


int main()
{
	ll n;
	scanf("%lld",&n);
	ll a[n+1];
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);

	// init DSU
	int par[n+1],size[n+1];
	int m[n+1],M[n+1];
	for(int i=1;i<=n;i++)
	{
	    par[i] = i;
        m[i] = a[i];
        M[i] = a[i];
	    size[i] = 1;
	}
	
	ll q;
	scanf("%lld",&q);
	while(q--)
	{
		ll x;
		scanf("%lld",&x);
		if( x==2 )
		{
			ll group;
			scanf("%lld",&group);
			int pg = getPar(group,par);
			printf("%lld\n",abs(M[pg]-m[pg]));
			
		}
		else
		{
			ll p1,p2;
			scanf("%lld %lld",&p1,&p2);
			int b = doUnion(p1,p2,par,size,m,M);

		}
	}
}