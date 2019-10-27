/*
	we will start setting bit from MSB if setting it exceeds R then we will not set it
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int


int maximumXOR(int n, int l, int r) 
{ 
    int x = 0; 
    for (int i = log2(r); i >= 0; --i) { 
        if (n & (1 << i)) 
        { 
            if ((x > r) or (x + (1 << i) - 1 < l)) 
                x ^= (1 << i); 
        } 
        
        else 
        { 
            if ((x ^ (1 << i)) <= r) 
                x ^= (1 << i); 
        } 
    } 
    return n ^ x; 
} 
int main()
{
	ll a,b,c;
	cin >> a >> b >> c;
	// vector<int> bin = no_bits(a);
	// for(int i=bin.size()-1;i>=0;i--)
	// 	cout << bin[i] << " ";
	// cout << endl;
	ll sum = 0;
	// for(int i=bin.size()-1;i>=0;i--)
	// {
	// 	if( bin[i]==0 )
	// 	{
	// 		if( (sum + pow(2,i)) <= c)
	// 			sum += pow(2,i);
	// 	}

	// }
	sum = maximumXOR(a,b,c);
	cout << sum << endl;
}