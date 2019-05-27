// given a string with numbers embedded into it, find the kth character in decrypted string ab2c3->ababccc
// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;
int main()
{
      string s;
      cin>>s;

      int xk;
      cin>>xk;
      xk--;
      int n = s.length();
      if(s[n-1]<'0' || s[n-1]>'9')
            s += '1';
      cout<<s<<endl;
      n = s.length();
      vector<int> nums;
      vector<string> ch;
      string temp ="";
      for(int i=0;i<n;)
      {
            if(s[i]>='0' && s[i]<='9')
            {
                  int x = 0;
                  while(s[i]>='0' && s[i]<='9')
                  {
                        x = x*10 + (s[i]-'0');
                        i++;
                  }
                  nums.push_back(x);
                  ch.push_back(temp);
                  temp="";
            }
            else
            {
                  temp += s[i];
                  i++;
            }
      }

      for(int i=0;i<ch.size();i++)
            cout<<ch[i]<<" ";
      cout<<endl;
      for(int i=0;i<nums.size();i++)
            cout<<nums[i]<<" ";
      cout<<endl;
      int pSum[n];
      pSum[0] = nums[0]*ch[0].length();
      for(int i=1;i<ch.size();i++)
      {
            pSum[i] = pSum[i-1] + ch[i].length()*nums[i];
      }
      for(int i=0;i<ch.size();i++)
            cout<<pSum[i]<<" ";
      cout<<endl;
      int ind;
      for(int i=0;i<ch.size();i++)
      {
            if(xk<pSum[i])
            {
                  ind = i;
                  break;
            }
      }
      int pos = xk%ch[ind].length();
      char ans;
      ans = ch[ind][pos];
      cout<<ans<<endl;
}
