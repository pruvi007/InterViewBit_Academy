

// prime factorization using Sieve + SPF --> O(Nlg(lgN))
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;

	int prime[n]={0};
	int SPF[n+1]={0};
	for(int i=2;i<=n;i++)
	{
		int l=2;
		while(l*i<=n)
		{
			prime[l*i] = 1;
			if(SPF[l*i]==0)
				SPF[l*i] = i;
			l++;
		}
		
		
	}
	for(int i=1;i<=n;i++)
		cout<<i<<":  "<<SPF[i]<<endl;
	// now prime factorize;

	// number of factors is summ (count+1)*  where count is count of each prime factor.
	
	int x = n;
	while(x!=1)
	{
		if(SPF[x]==0)
		{
			cout<<x<<endl;
			break;
		}
		cout<<SPF[x]<<" ";
		x = x/SPF[x];
	}
	cout<<endl;
}