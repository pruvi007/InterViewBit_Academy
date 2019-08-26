/*
	A two player game.
	You can choose only corner elements and then chance of opponent
*/
// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll mem[1001][1001];
ll game(int a[],int l,int r)
{
	if( l==r )
		return a[l];
	if( r==l+1 )
		return max(a[r],a[l]);

	if( mem[l][r] != -1 )
		return mem[l][r];
	
	mem[l][r] = max( a[l]+min( game(a,l+2,r),game(a,l+1,r-1) ), a[r]+min(game(a,l,r-2),game(a,l+1,r-1)) );
	return mem[l][r];


}
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n];
		for( int i=0;i<n;i++ )
			cin >> a[i];

		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
				mem[i][j] = -1;

		ll ans = game(a,0,n-1);
		cout << ans << endl;
	}
}