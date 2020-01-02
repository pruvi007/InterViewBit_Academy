#include<bits/stdc++.h>
using namespace std;
map<string,int> m;
void word_break( string s,string res)
{
      int l = s.length();
      for(int i=1;i<=l;i++)
      {
            string pre = s.substr(0,i);
            // cout << "pre:" << pre << endl;
            if( m.find(pre)!=m.end() )
            {
                  // cout << "here\n";
                  if(i==l)
                  {
                        res += pre;
                        cout << res << endl;
                        return;
                  }
                  word_break(s.substr(i,l),res+pre+" ");
            }
      }
}
int main()
{
      string s;
      cin >> s;
      int l = s.length();
      vector<string> b;
      int n;
      cin >> n ;
      for(int i=0;i<n;i++)
      {
            string x;
            cin >> x;
            b.push_back(x);
            m[x] = 1;
      }
      word_break( s,"" );
      return 0;
}
