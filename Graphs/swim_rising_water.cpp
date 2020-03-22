#include<bits/stdc++.h>
using namespace std;

bool vis[1001][1001];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void updateWater( vector<vector<int> > v, vector<vector<int> > &water,int time )
{
    int n = v.size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if( v[i][j] <= time )
                water[i][j] = 1;
        }
    }
}
bool safe( int x,int y,int n )
{
    return x>=0 and x<n and y>=0 and y<n;
}

bool reached = false;
void dfs( int x,int y, vector<vector<int> > water )
{
    int n = water.size();
    cout << x << "," << y << endl;
    if( x==n-1 and y==n-1 )
    {
        reached = true;
        return;
    }
    vis[x][y] = true;
    for(int i=0;i<4;i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if( safe(nx,ny,water.size()) and vis[nx][ny]==false and water[nx][ny]==1 )
            dfs(nx,ny,water);
    }
    return ;
}
void path( vector<vector<int> > water )
{
    reached = false;
    memset( vis,false,sizeof(vis) );
    dfs( 0,0,water );
    cout << reached << endl;
    return;
}
int main()
{
    int n;
    cin >> n;
    vector< vector<int> > v(n,vector<int>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cin >> v[i][j];
    }
    vector< vector<int> > water(n,vector<int>(n,0));
    int ans = 0;
    int time = 0;

    // following times out for n = 50
    while(true){
        updateWater( v,water,time );
        cout << "At time : " << time << endl;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cout << water[i][j] << " " ;
            cout << endl;
        }
        if( water[0][0]==1)
        {
            path( water );
            if( reached ){
                ans = time;
                break;
            }
           
        }
        time += 1; 
        if(time >= 20)
            break;
    }
    cout << ans << endl;
}