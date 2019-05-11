

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	int a[n*m];
	for(int i=0;i<n*m;i++)
		cin>>a[i];
	sort(a,a+n*m);
	int k;
	cin>>k;
	int poss = 0;
	int prev = a[0]%k;
	for(int i=1;i<n*m;i++)
	{
		if(a[i]%k != prev)
		{
			poss = 1;
			break;
		}
	}
	if(poss == 1)
		cout<<"-1\n";
	else
	{
		if(n*m%2 == 0)
		{
			int med1 = a[n*m/2];
			int med2 = a[(n*m-1)/2];
			int steps1 = 0, steps2=0;
			for(int i=0;i<n*m;i++)
			{
				steps1 += abs(a[i] - med1)/k;
				steps2 += abs(a[i] - med2)/k;
			}
			cout<<min(steps1,steps2)<<endl;

		}
		else
		{
			int med = a[n*m/2];
			int steps = 0;
			for(int i=0;i<n*m;i++)
			{
				steps += abs(a[i] - med)/k;
			}
			cout<<steps<<endl;
		}
	}
}