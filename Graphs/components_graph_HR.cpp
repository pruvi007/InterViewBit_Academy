#include<bits/stdc++.h>
using namespace std;

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
int main(){
    int n;
    cin >> n;
    // init DSU
    int par[2*n+1],size[2*n+1];
    for(int i=1;i<=2*n;i++)
    {
        par[i] = i;
        size[i] = 1;
    }
    int max_val = 0;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin >> x >> y;
        max_val = max(max_val,max(x,y));
        int ans = doUnion(x,y,par,size);

    }
    
    
    int m=INT_MAX,M=INT_MIN;
    for(int i=1;i<=2*n;i++)
    {
        // imp : get set size of every unique parent
        int x = getPar(i,par);
        if(size[x] < m && size[x]>1)
            m = size[x];
        if(size[x]>M && size[x]>1)
            M = size[x];
    }
    cout << m << " " << M << endl;
}
