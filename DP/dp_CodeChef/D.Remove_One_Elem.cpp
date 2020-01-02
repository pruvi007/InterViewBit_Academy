#include<bits/stdc++.h>
using namespace std;
vector<int> lis(int a[],int n)
{
      vector<int> l;
      l.push_back(a[0]);
      for(int i=1;i<n;i++)
      {
            auto p = upper_bound( l.begin(),l.end(),a[i] );
            if(p == l.end())
                  l.push_back(a[i]);
            else
                  l[*p] = a[i];
      }
      return l;
}
int main()
{
      int n;
      cin >> n ;
      int a[n];
      for(int i=0;i<n;i++)
            cin >> a[i];
      vector<int> l = lis(a,n);
      for(int i=0;i<l.size();i++)
            cout << l[i] << " ";
      cout << endl;

}
