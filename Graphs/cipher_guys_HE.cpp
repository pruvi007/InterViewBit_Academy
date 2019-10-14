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


int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        ll n,q;
        scanf("%lld %lld",&n,&q);

        // init DSU
        int par[n+1],size[n+1];
        for(int i=1;i<=n;i++)
        {
            par[i] = i;
            size[i] = 1;
        }

        int yes=0,no=0;
        while(q--)
        {
            char ch;
            scanf(" %c",&ch);
            if( ch=='J')
            {
                int x,y;
                scanf("%d %d",&x,&y);
                int b = doUnion(x,y,par,size);
            }
            else
            {
                int x,y;
                scanf("%d %d",&x,&y);
                if( find(x,y,par) )
                    yes++;
                else
                    no++;
            }
        }
        cout << yes << " " << no << endl;
    }

	
}