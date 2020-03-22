#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[100][100],sol[100][100];
int dx[] = {0,1};
int dy[] = {1,0};

bool safe(int x,int y)
{
    return x>=0 and y>=0 and x<n and y<m and a[x][y]==0;
}
void rat(int x,int y)
{
    if( x==n-1 and y==m-1 )
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                cout << sol[i][j] << " ";
            cout << endl;
        }
        cout << endl;
        return;
    }

    for(int i=0;i<2;i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if( safe(nx,ny) )
        {
            sol[nx][ny] = 1;
            rat(nx,ny);
            sol[nx][ny] = 0;
        }
    }
}
int main(){
    
    cin >> n >> m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> a[i][j];
    cout << endl;
    sol[0][0] = 1;
    rat(0,0);
}