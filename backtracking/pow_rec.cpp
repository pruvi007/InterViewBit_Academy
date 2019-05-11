#include<bits/stdc++.h>
using namespace std;
#define ll long long int


// recursive-Power O(logn)

ll pow_2(ll a,ll b)
{
	if(b==0)
		return 1;

	ll x = pow_2(a,b/2);
	if(b%2==0)
	{
		return x*x;
	}
	else
		return x*x*a;

}

// if we are dividing in  more parts, dont think that time complexity is decreasing.. (constant operations are increasing.. so time would remain almost similar.)
ll pow_3(ll a,ll b)
{
	if(b==0)
		return 1;

	ll x = pow_3(a,b/3);
	if(b%3==0)
		return x*x*x;
	else if(b%3==1)
		return x*x*x*a;
	else 
		return x*x*x*a*a;


}

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll a,b;
		cin>>a>>b;
		cout<<pow_2(a,b)<<endl;
		cout<<pow_3(a,b)<<endl;

	}
}