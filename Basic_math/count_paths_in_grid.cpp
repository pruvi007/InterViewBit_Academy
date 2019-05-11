

// count paths from (0,0) to (n-1,m-1)
// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;

// get (m+n-2) C (m-1)
// if you choose more than (m-1), you will go out of the grid

int fact(int n)
{
	if(n==0)
		return 1;
	int f = 1;
	for(int i=1;i<=n;i++)
		f = f*i;
	return f;
}
int C(int a,int b)
{
	int num = fact(a);
	int den = fact(a-b)*fact(b);
	return num/den;
}
int main()
{
	int n,m;
	cin>>n>>m;
	int num = (m+n-2);
	int den = (m-1);
	int ans = C(num,den);
	cout<<ans<<endl;

}