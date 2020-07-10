#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll mod = 1000000007;
ll count(string a, string b) 
{ 
    int m = a.length(); 
    int n = b.length(); 
    int lookup[m + 1][n + 1] = { { 0 } }; 
    for (int i = 0; i <= n; ++i) 
        lookup[0][i] = 0; 

    for (int i = 0; i <= m; ++i) 
        lookup[i][0] = 1; 
 
    for (int i = 1; i <= m; i++) 
    { 
        for (int j = 1; j <= n; j++) 
        { 
            if (a[i - 1] == b[j - 1]) 
                lookup[i][j] = lookup[i - 1][j - 1] +  lookup[i - 1][j]; 
                  
            else
                lookup[i][j] = lookup[i - 1][j]; 
           	lookup[i][j] %= mod;
        } 
    } 
  
    return lookup[m][n]%mod; 
} 
int main(){
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		string s;
		cin >> s;
		string b = "abcdefghijklmnopqrstuvwxyz";
		ll ans = count(s,b);
		cout << ans%mod << '\n';
	}
}