#include<bits/stdc++.h>
using namespace std;
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string p,q;
        cin>>p>>q;
        // cout << p << q << endl;
        int n=p.length();
        int m=q.length();
        vector<char> p1;
        vector<char> q1;
        int c=0;
        bool f=false;
        for(int i=n-1;i>=0;i--)
        {
            if(p[i]=='#')
            {
                c+=1;
                f=true;
                continue;
            }
            else
            {
                if(f==true)
                {
                    f=false;
                }
                c%=26;
                char x=char(65+(p[i]%65+c)%26);
                p1.push_back(x);
                c=0;
            }
        }
        c=0;
        f=false;
        for(int i=m-1;i>=0;i--)
        {
            if(q[i]=='#')
            {
                c+=1;
                f=true;
                continue;
            }
            else
            {
                if(f==true)
                {
                    f=false;
                }
                c%=26;
                char x=char(65+(q[i]%65+c)%26);
                q1.push_back(x);
                c=0;
            }
        }
        string ans1="";
        string ans2="";
        for(int i=p1.size()-1;i>=0;i--)
        {
            ans1+=p1[i];
        }
        for(int i=q1.size()-1;i>=0;i--)
        {
            ans2+=q1[i];
        }
        if(ans1==ans2)
        {
            cout<<"Yes\n";
        }
        else
        {
            cout<<"No\n";
        }
       }
return 0;
 }