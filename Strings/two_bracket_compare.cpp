/*
      given tWO arithmetic expression, determine whether the two are equivalent or not.
*/
// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;
int main()
{
      string a,b;
      cin>>a>>b;
      string mod_a="",mod_b="";
      stack<char> s1,s2;
      s1.push('+');
      s2.push('+');


      int n = a.length();
      int n2 = b.length();
      for(int i=0;i<n;i++)
      {
            if(a[i]>='a' && a[i]<='z')
            {
                  mod_a += a[i];
            }
            else
            {
                  if(a[i]=='-')
                  {
                        if(i+1<n && a[i+1]=='(')
                        {
                              if(s1.top()=='-')
                              {
                                    mod_a += '+';
                                    s1.push('+');
                              }
                              else if(s1.top()=='+')
                              {
                                    mod_a += '-';
                                    s1.push('-');
                              }
                        }
                        else
                        {
                              if(s1.top()=='-')
                              {
                                    mod_a += '+';
                              }
                              else if(s1.top()=='+')
                              {
                                    mod_a += '-';
                              }
                        }
                  }
                  else if(a[i]=='+')
                  {
                        if(i+1<n && a[i+1]=='(')
                        {
                              if(s1.top()=='-')
                              {
                                    mod_a += '-';
                                    s1.push('-');
                              }
                              else if(s1.top()=='+')
                              {
                                    mod_a += '+';
                                    s1.push('+');
                              }
                        }
                        else
                        {
                              if(s1.top()=='-')
                              {
                                    mod_a += '-';
                              }
                              else if(s1.top()=='+')
                              {
                                    mod_a += '+';
                              }
                        }
                  }
                  else if(a[i]==')')
                        s1.pop();

            }
      }
      for(int i=0;i<n2;i++)
      {
            if(b[i]>='a' && b[i]<='z')
            {
                  mod_b += b[i];
            }
            else
            {
                  if(b[i]=='-')
                  {
                        if(i+1<n2 && b[i+1]=='(')
                        {
                              if(s2.top()=='-')
                              {
                                    mod_b += '+';
                                    s2.push('+');
                              }
                              else if(s2.top()=='+')
                              {
                                    mod_b += '-';
                                    s2.push('-');
                              }
                        }
                        else
                        {
                              if(s2.top()=='-')
                              {
                                    mod_b += '+';
                              }
                              else if(s2.top()=='+')
                              {
                                    mod_b += '-';
                              }
                        }
                  }
                  else if(b[i]=='+')
                  {
                        if(i+1<n2 && b[i+1]=='(')
                        {
                              if(s2.top()=='-')
                              {
                                    mod_b += '-';
                                    s2.push('-');
                              }
                              else if(s2.top()=='+')
                              {
                                    mod_b += '+';
                                    s2.push('+');
                              }
                        }
                        else
                        {
                              if(s2.top()=='-')
                              {
                                    mod_b += '-';
                              }
                              else if(s2.top()=='+')
                              {
                                    mod_b += '+';
                              }
                        }
                  }
                  else if(b[i]==')')
                        s2.pop();

            }
      }
      cout<<mod_a<<endl;
      cout<<mod_b<<endl;

      if(mod_a == mod_b)
            cout<<"1\n";
      else cout<<"0\n";

}
