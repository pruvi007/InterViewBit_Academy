/*
      perform Rabin Karp String matching
      hash used here:- sum(s[i]*p^i)
      where p = prime no. say 3 and i is the index.
*/
// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
int main()
{
      int t;
      cin>>t;
      while(t--)
      {
            string p,s;
            cin>>p>>s;

            ll hp = 0;
            ll pr =1;
            int n = p.length();
            int m = s.length();
            for(int i=0;i<n;i++)
            {
                  int x = p[i];
                  hp = hp + x*pr;
                  pr = pr*3;
            }

            ll hs=0;
            pr = 1;
            for(int i=0;i<n;i++)
            {
                  int x = s[i];
                  hs = hs + x*pr;
                  pr = pr*3;
            }

            ll ans = 0;
            ll const_pr = pow(3,n-1);
            for(int i=n;i<=m;i++)
            {
                  if(hs == hp)
                  {
                        // if hashes match, then to confirm compare character wise
                        int cp = 0;
                        int flag=0;
                        for(int j=i-n;j<i;j++)
                        {
                              if(s[j] != p[cp])
                              {
                                    flag=1;
                                    break;
                              }
                              cp++;
                        }
                        if(flag==0)
                              ans++;
                  }
                  else
                  {
                        int curr = s[i];
                        int prev = s[i-n];
                        hs = curr*const_pr + (hs - prev)/3;
                  }
            }

            cout<<ans<<endl;

      }
}
