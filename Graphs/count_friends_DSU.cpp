/*
	count the total no of friends using DSU.
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;

int getRoot(int x,int par[])
{
	while(x != par[x])
	{
		x = par[x];
	}
	return x;
}
int find(int x,int y,int par[])
{
	return getRoot(x,par) == getRoot(y,par);
}
int doUnion(int x,int y,int par[],int size[])
{
	if(find(x,y,par))
		return -1;
	int p1 = getRoot(x,par);
	int p2 = getRoot(y,par);
	int s1 = size[p1];
	int s2 = size[p2];
	// now do path comp
	if(s1 > s2)
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
int main()
{
	int n,m;
	cin >> n >> m;

	// init the DSU
	int par[n+1],size[n+1];
	for(int i=1;i<=n;i++)
	{
		par[i] = i;
		size[i] = 1;
	}

	// start doing union
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin >> x >> y;
		int z = doUnion(x,y,par,size);
	}
	// print the sizes
	for(int i=1;i<=n;i++)
	{
		int x = getRoot(i,par);
		cout << size[x]-1 << " ";
	}
	cout << endl;
}