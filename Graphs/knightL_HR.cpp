// solution by @pruvi007
// use direction array to make the knight move on the chess board and use Is Safe function

#include<bits/stdc++.h>
using namespace std;
int isSafe(int x,int y,int n)
{
    return x>=0 && x<n && y>=0 && y<n;
}
int main(){
    int n;
    cin >> n;

    int v[n][n];
    for(int i=1;i<n;i++)
    {
        
        for(int j=i;j<n;j++)
        {
            
            int a = i;
            int b = j;
            int dx[] = {-a,-b,b,a,a,b,-b,-a};
            int dy[] = {b,a,a,b,-b,-a,-a,-b};
            queue< pair<int ,pair<int,int> > > q;
            q.push({0,{0,0}});
            int steps = -1;
            map<pair<int,int>,int> m;
            int flag=0;
            while(!q.empty())
            {
                pair<int,pair<int,int> > p = q.front();
                // cout << p.first << " " << p.second << endl;
                q.pop();
                m[{p.second.first,p.second.second}] = 1;
                
                if(p.second.first==n-1 && p.second.second==n-1)
                {
                    flag=1;
                    steps = p.first;
                    break;
                }
                for(int z=0;z<8;z++)
                {
                    int x = p.second.first+dx[z];
                    int y = p.second.second+dy[z];
                    if(isSafe(x,y,n) && m.find({x,y})==m.end())
                    {
                        m[{x,y}] = 1;
                        q.push({p.first+1,{x,y}});
                    }
                        

                }
            }
            v[i-1][j-1] = steps;
            v[j-1][i-1] = steps;
            
        }
        
        
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1;j++)
            cout << v[i][j] << " ";
        cout << endl;
    }
}
