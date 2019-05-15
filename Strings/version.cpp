/*
	compare two version numbers
*/

// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	string a,b;
	cin>>a>>b;

	int n1 = a.length();
	int n2 = b.length();

	int ans = 2;
	for(int i=0,j=0;i<n1 || j<n2;)
	{
		ll num1 = 0;
		
		while(i<n1 && a[i]!='.')
		{
			int x = a[i]-'0';
			num1 = num1*10 + x;
			i++;
		}
		ll num2= 0;
		while(j<n2 && b[j]!='.')
		{
			int x = b[j]-'0';
			num2 = num2*10 +x;
			j++;
		}

		cout<<num1<<endl;
		cout<<num2<<endl<<endl;
		if(num1>num2)
		{
			ans = 1;
			break;
		}
		else if(num1<num2)
		{
			ans = -1;
			break;
		}
		i++;
		j++;
	}
	if(ans ==2)
		ans = 0;
	cout<<ans<<endl;
}