#include<bits/stdc++.h>
using namespace std;

// to get the root (representative)
int getRoot(int i,int *par)
{
	while(i!=par[i])
	{
		i = par[i];
	}
	return i;
}

// checks if the given nodes belong to same set or not
int find(int a,int b,int *par)
{
	return getRoot(a,par) == getRoot(b,par);
}

int doUnion(int a,int b,int *par,int *size)
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

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int a[n][n];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin >> a[i][j];
        
        vector<pair<int,pair<int,int> > > v;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j and a[i][j]>0)
                {
                    int w = a[i][j];
                    v.push_back({w,{i+1,j+1}});
                }
            }
        }
       
        sort(v.begin(),v.end());

        // build your DSU (initialize parents and size)
        int par[n+1],size[n+1];
        for(int i=1;i<=n;i++)
        {
            par[i] = i;
            size[i] = 1;
        }

        int sum = 0;
        for(int i=0;i<v.size();i++)
        {
            int x = doUnion(v[i].second.first,v[i].second.second,par,size);
            if(x==1)
                sum += v[i].first;
            
        }
        cout << sum << "\n";
    }
	

}