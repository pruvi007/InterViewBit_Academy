#include<bits/stdc++.h>
using namespace std;

int curHasPower(vector<vector<int>>&c,vector<int>&cur)
{
    for(int i=0;i<c.size();i++)
    {
        int x = c[i][0];
        int y = c[i][1];
        if(cur[0]==x and cur[1]==y)
            return c[i][2];
    }
    return -1;
}
int main(){
    int n,m,s;
    cin >> n >> s >> m;
    vector< vector<int> > p;
    for(int i=0;i<m;i++)
    {
        int x,y,z;
        cin >> x >> y >> z;
        p.push_back(vector<int>{x,y,z});
    }

    //generate Spiral coordinates
    vector< vector<int> > c;
    int l=0,r=0;
    while(l!=n/2 and r!=n/2)
    {
        // left->right
        
        for(int j=r;j<n-r;j++)
        {
            c.push_back(vector<int>{l,j});
        }
        
        //top-bottom
        for(int i=l+1;i<n-l;i++)
        {
            c.push_back(vector<int>{i,n-r-1});
        }

        //left->right
        for(int i=n-r-2;i>=r;i--)
        {
            c.push_back(vector<int>{n-l-1,i});
        }

        //bottom->top
        for(int i=n-l-2;i>l;i--)
        {
            c.push_back(vector<int>{i,r});
        }
        l+=1;r+=1;
    }
    if(n&1)
        c.push_back(vector<int>{n/2,n/2});
    // for(int i=0;i<c.size();i++)
    //     cout << c[i][0] << "," << c[i][1] << endl;
    int reach = s;
    bool valid = false;
    for(int i=0;i<reach;i++)
    {
        vector<int> cur = c[i];
        int power = curHasPower(p,cur);
        // cout << cur[0] << "," << cur[1] << endl;
        // cout << reach << " " << power << '\n';
        // cout << endl;
        if( power!=-1 )
        {
            reach = max(reach,i+power);
            if(reach>=c.size())
            {
                valid = true;
                break;
            }
        }
    }
    if(valid)
        cout << "Yes\n";
    else cout << "No\n";

    
}