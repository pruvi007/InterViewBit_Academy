#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        int l = s.length();
        if(l==1)
            cout<<"1\n";
        else if(l==2)
        {
            if(s[0]==s[1])
                cout<<"2\n";
            else cout<<"1\n";
        }
        else
        {
            ll m1=1,m2=0;
            for(int i=0;i<l;i++)
            {

                //considering single center (odd length palindrome)
                if((i-1)>=0 && (i+1)<l)
                {
                    int l1 = i-1;
                    int r1 = i+1;
                    while(l1>=0 && r1<l && s[l1] == s[r1])
                    {
                         if((r1-l1+1)>m1)
                            m1=r1-l1+1;
                        l1--;
                        if(l1<0)
                            break;
                        r1++;
                        if(r1>=l)
                            break;

                    }
                }


                //considering double center (even length palindrome)
                if(s[i] == s[i+1])
                {
                    if(2>m2)
                        m2 = 2;
                    if((i-1)>=0 && (i+2)<l)
                    {
                        int l2 = i-1;
                        int r2 = i+2;
                        while(l2>=0 && r2<l && s[l2] == s[r2])
                        {
                            if((r2-l2+1)>m2)
                                m2 = r2-l2+1;
                            l2--;
                            if(l2<0)
                                break;
                            r2++;
                            if(r2>=l)
                                break;

                        }
                    }

                }
            }
            ll ans = m1>m2?m1:m2;
            cout<<ans<<endl;
        }

    }
}
