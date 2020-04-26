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
        int n,q;
        cin >> n >> q;
        map<char,int> mp;
        char a[n];
        int l=1;
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
            if(mp.find(a[i])==mp.end())
            {
                mp[a[i]]=l;
                l++;
            }
        }
        int par[n+1],size[n+1];
        for(int i=0;i<=n;i++)
            par[i]=i;
        for(int i=0;i<=n;i++)
            size[i] = 1;
        for(int i=0;i<q;i++)
        {
            string s;
            int a,b;
            cin >> s >> a >> b;
            if(s=="addincircle")
            {
                int x,y;
                x = mp[a];
                y = mp[b];
                int ans = doUnion(x,y,par,size);
            }
            else
            {
                int x,y;
                x = mp[a];
                y = mp[b];
                int ans = find(x,y,par);
                if(ans)
                    cout << "1\n";
                else 
                    cout << "0\n";
            }
            
        }
    }
	

}