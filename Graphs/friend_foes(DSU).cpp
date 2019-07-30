/*
	do union for friend relations
	undo the union in case of enemies
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;

int getRoot(int x,int par[])
{
	while(x!=par[x])
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
	if(s1>s2)
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
	int n;
	cin >> n;
	// init DSU
	int par[n+1],size[n+1];
	for(int i=1;i<=n;i++)
	{
		par[i] = i;
		size[i] = 1;
	}
	int fr;
	cin >> fr;
	for(int i=0;i<fr;i++)
	{
		int x,y;
		cin >> x >> y;
		int ans = doUnion(x,y,par,size);
	}
	int foe;
	cin >> foe;
	for(int i=0;i<foe;i++)
	{
		int x,y;
		cin >> x >> y;
		if(find(x,y,par))
		{
			int p = getRoot(x,par);
			// if(p != x)
			// {
			// 	size[p]--;
			// 	par[x] = x;
			// }
			size[p] = 0;
		}

	}
	int max = 0;
	for(int i=1;i<=n;i++)
	{
		if(par[i]==i)
		{
			max = max>size[i]?max:size[i];
		}
	}
	cout << max << endl;
}