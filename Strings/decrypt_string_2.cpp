/*
      apart from previous decrypt strings, this is double decrypted strings.
      ab2c3 -> ababcababcababc
*/
// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;

int main()
{
      string s;
      cin>>s;
      int n = s.length();

      if(s[n-1]<'0' || s[n-1]>'9')
            s += '1';
      n +=1;

      int k;
      cin>>k;
      int len = 0;
      stack<pair<char,int> > st;

      for(int i=0;i<n;)
      {
            if(s[i]<'0' || s[i]>'9')
            {
                  len++;

                  st.push({s[i],len});
                  if(len>=k)
                        break;


                  i++;
            }
            else
            {
                  int num = 0;
                  while(s[i]>='0' && s[i]<='9')
                  {
                        num = num*10 + s[i]-'0';
                        i++;
                  }
                  len = len*num;
                  
            }

      }
      // cout<<len<<endl;
      char ans;
      while(!st.empty())
      {
            pair<char,int> p = st.top();
            cout<<p.first<<" "<<p.second<<endl;
            k = k%p.second;
            if(k==0)
            {
                  ans = p.first;
                  break;
            }
            st.pop();
      }
      cout<<ans<<endl;
}
