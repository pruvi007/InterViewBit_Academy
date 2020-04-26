#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    vector< string > v;
    for(int i=0;i<n;i++)
    {
        string s;
        cin >> s;
        v.push_back(s);
    }
    vector<int> col,row;
    for(int i=0;i<m;i++)
    {
        int c = 0;
        for(int j=0;j<n;j++)
        {
            if(v[j][i]=='g')
                c++;
        }
        col.push_back(c);
    }

    for(int i=0;i<n;i++)
    {
        int c = 0;
        for(int j=0;j<m;j++)
        {
            if(v[i][j]=='g')
                c++;
        }
        row.push_back(c);
    }
    // for(int i=0;i<col.size();i++)
    //     cout << col[i] << " ";
    // cout << endl;
    // for(int i=0;i<row.size();i++)
    //     cout << row[i] << " ";
    // cout << endl;

    int ans = 100000;
    for(int i=1;i<n-1;i++)
    {
        for(int j=0;j<m;j++)
        {
            if( v[i][j]=='g' and (v[i-1][j]=='g' or v[i+1][j]=='g')  )
                ans = min(ans,col[j]);
        }
    }
    for(int i=1;i<m-1;i++)
    {
        for(int j=0;j<n;j++)
        {
            if( v[j][i]=='g' and ( v[j][i-1]=='g' or v[j][i+1]=='g' ) )
                ans = min(ans,row[j]);
        }
    }
    cout << (ans==100000?1:ans) << "\n";
    
}