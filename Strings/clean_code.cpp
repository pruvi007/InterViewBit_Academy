/*
      remove comments and multi line commments from the code.
*/
// solution by @pruvi007

#include <bits/stdc++.h>
using namespace std;
int main()
{
      int n;
      cin>>n;

      int flag=0;
      vector<string> ans;
      for(int i=0;i<n;i++)
      {
            string x;
            getline (cin, x);
            int l = x.length();
            if(l==0)
            {
                  continue;
            }
            if(x[0]=='/' && x[1]=='/')
            {
                  int cm=0;
                  for(int j=0;j<x.length()-1;j++)
                  {
                        if(x[j]=='/' && x[j+1]=='/')
                        {
                              cm=1;
                              break;
                        }
                  }
                  if(cm==1)
                        continue;
            }
            if(x[0]=='/' && x[1]=='*')
            {
                  flag=1;
                  continue;
            }
            if(flag==0)
                  ans.push_back(x);
            if(flag==1)
            {
                  for(int j=0;j<x.length()-1;j++)
                  {
                        if(x[j]=='*' && x[j+1]=='/')
                        {
                              flag=0;
                              break;
                        }
                  }
            }


      }
      cout<<endl;
      for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<endl;
}
