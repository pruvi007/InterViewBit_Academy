// same format string
// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;
int main()
{
	string a,b;
	cin>>a>>b;
	int n1 = a.length();
	int n2 = b.length();

	int i=0,j=0;
	int flag=0;
	while(i<n1 && j<n2)
	{
		if(a[i]==b[j])
		{
			while(a[i]==b[j])
				j++;
			i++;
		}
		else
		{
			flag=1;
			break;
		}
	}
	if(i!=n1 || j!=n2 || flag)
		cout<<"0\n";
	else cout<<"1\n";
}