#include<bits/stdc++.h>
using namespace std;

int solve(vector<string> &v,int n)
{
    int l=0;
    map<string,int> mp;
    string s = v[0];
    
   
    
        int mi = INT_MAX;
        // cout << s << endl;
        int m = s.length();
        vector<string> rots;
        for(int i=0;i<n;i++)
        {
            int l = 0;
            string x = v[i];
            map<string,int> local;
            for(int j=0;j<m;j++)
            {
                string rot = "";
                for(int k=l;k<m;k++)
                    rot += x[k];
                for(int k=0;k<l;k++)
                    rot += x[k];
                rots.push_back(rot);
                local[rot]++;
                l++;
            }
            for(int j=0;j<n;j++)
            {
                if( local.find(v[j])==local.end() )
                    return -1;
            }
            
        }
       
        for(int i=0;i<rots.size();i++)
        {
            
            // string rot = "";
            // for(int j=l;j<m;j++)
            //     rot += s[j];
            // for(int j=0;j<l;j++)
            //     rot += s[j];
            // cout << rots[i] << " : ";
            int steps = 0;
            for(int j=0;j<n;j++)
            {
                int l=0,r=0;
                
                // cout << v[j] <<":" ;
                if(v[j]!=rots[i])
                {
                    int c = 0;
                    while( l<m and r<m )
                    {
                        if(rots[i][l]==v[j][r])
                        {
                            l++;
                            r++;
                            c++;
                        }
                        else
                            r++;
                        if(r==m)
                            break;
                    }
                    // cout << m-l << "   " ;
                    steps += m-l;
                }
                // else
                //     cout << 0 << "   ";
                

            }
            // cout << endl;
            mi = min(steps,mi);
            l++;
        }
        return mi;
    
   
}
int main()
{
    int n;
    cin >> n;
    vector<string> v(n);
    for(int i=0;i<n;i++)
        cin >> v[i];
    int ans = solve(v,n);
    cout << ans << endl;
}

/*
adam,mdaa
*/