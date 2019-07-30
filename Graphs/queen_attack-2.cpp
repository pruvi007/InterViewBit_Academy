/*
    find the number of cells that can be attacked by a queen + board contains obstacles which can block queen's path
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;

int safe(int a,int b,int n)
{
    return (a<=n && b<=n && a>=1 && b>=1);
}
int main(){
    int n,k;
    cin >> n >> k;
    int x,y;
    cin >> x >> y;
    map<pair<int,int>,int>  m;
    for(int i=0;i<k;i++)
    {
        int a,b;
        cin >> a >> b;
        m[{a,b}] = 1;
    }

    // 8 directional paths
    int dx[] = {0,-1,-1,-1,0,1,1,1};
    int dy[] = {-1,-1,0,1,1,1,0,-1};
    int cell = 0;
    for(int i=0;i<8;i++)
    {
        int a = x;
        int b = y;
        // keep going in that direction unitll (out of bound or found and obstacle)
        while(1)
        {
            a = a+dx[i];
            b = b+dy[i];
            if(safe(a,b,n))
            {
                if(m.find({a,b}) != m.end())
                    break;
                cell++;
            }
            else break;
            
        }
    }
    cout << cell << endl;
}