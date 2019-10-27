

/*
	A component of c vertices will satisfy c-1 animals.
	using dsu find the size of each component
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;

// to get the root (representative)
int getRoot(int i,int par[])
{
	while(i!=par[i])
	{
		i = par[i];
	}
	return i;
}

// checks if the given nodes belong to same set or not
int find(int a,int b,int par[])
{
	return getRoot(a,par) == getRoot(b,par);
}

int doUnion(int a,int b,int par[],int size[])
{
	if(find(a,b,par) == 1)
		return -1;
	int r1 = getRoot(a,par);
	int r2 = getRoot(b,par);
	int s1 = size[r1];
	int s2 = size[r2];
	if(s1 > s2)
	{
		par[r2] = r1;
		size[r1] += s2;
	}
	else
	{
		par[r1] = r2;
		size[r2] += s1;
	}
	return 1;
}
int main()
{
	int n,m;
	cin >> n >> m;
	// init dsu
	int par[n+1],size[n+1];
	for(int i=1;i<=n;i++)
	{
		par[i] = i;
		size[i] = 1;
	}
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin >> x >> y;
		int z = doUnion(x,y,par,size);
	}
	int satify = 0;
	unordered_map<int,int> mp;
	for(int i=1;i<=n;i++)
	{
		int p = getRoot(i,par);
		if( mp.find(p)==mp.end() )
		{
			mp[p]++;
			satify += size[p]-1;
		}
	}
	int ans = m - satify;
	cout << ans << endl;
}