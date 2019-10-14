#include<bits/stdc++.h>
using namespace std;

set<int,greater<int> > st;
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
        st.insert(size[p1]);
    }
    else
    {
        par[p1] = p2;
        size[p2] += s1;
        st.insert(size[p2]);
    }
    return 1;
}


int main()
{
	int n,q;
	cin >> n >> q;
	string s;
	cin >> s;
	char a[n+1];
	for(int i=0;i<n;i++)
		a[i+1] = s[i];
	// init DSU
    int par[n+1],size[n+1];
    for(int i=1;i<=n;i++)
    {
        par[i] = i;
        if(a[i]=='1')
        	size[i] = 1;
        else
        	size[i] = 0;
    }
    st.insert(0);
    while(q--)
    {
    	int x;
    	cin >> x;
    	if( x==1 )
    	{
    		
    		cout << *st.begin() << endl;
    		
    	}
    	else
    	{
    		int p;
    		cin >> p;
    		a[p] = '1';
    		if( size[p]==0 )
    			size[p] = 1;
    		int p1 = -1;
    		int p2 = -1;
    		if(p-1>=1 and a[p-1]=='1')
    			p1 = p-1;
    		if(p+1<=n and a[p+1]=='1')
    			p2 = p+1;

    		// cout << p1 << " " << p2 << endl;
    		if( p2==-1 and p1==-1)
    		{
    			st.insert(1);
    		}
    		else if( p1==-1 and p2!=-1)
    		{
    			int b = doUnion(p,p2,par,size);
    		}
    		else if( p1!=-1 and p2==-1)
    		{
    			int b = doUnion(p,p1,par,size);
    		}
    		else
    		{
    			int b = doUnion(p,p2,par,size);
    			b = doUnion(p,p1,par,size);
    		}
    		
    	}
    }
}