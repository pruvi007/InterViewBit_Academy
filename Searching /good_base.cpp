#include<bits/stdc++.h>
using namespace std;

#define ll long long int
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string A;
		cin>>A;
		ll num = 0;
	    ll b = 1;
	    int l = A.length();
	    for(int i=l-1;i>=0;i--)
	    {
	        int x = A[i]-'0';
	        num += b*x;
	        b*=10;
	    }
	    cout<<num<<endl;
	    ll low = 2,high = num;
	    
	    int r = log2(num);
	    ll ans = r;
	    for(int i=2;i<=r;i++)
	    {
	        
	        ll x = num;
	        int valid = 0;
	        while(x)
	        {
	            if(x%i!=1)
	            {
	                valid = 1;
	                break;
	            }
	            x /= i;
	        }
	        if(valid == 0)
	        {
	            ans = i;
	            break;
	        }
	        
	    }
	    
	    string s = to_string(ans);
	    cout<<s<<endl;
	}
}