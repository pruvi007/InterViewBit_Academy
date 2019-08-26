/*
	Find the longest alternating sequence
	maintain two dps -> one that ends greater and one that ends with smaller
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n];
		for(int i=0;i<n;i++)
			cin >> a[i];
		int las[2][n];
		for(int i=0;i<n;i++)
			las[0][i] = las[1][i] = 1;

		/*
			dp states
			las[0][i] -> length of LAS considering ith is greater
			las[1][i] -> length of LAS considering ith is smaller
		*/

		for(int i=1;i<n;i++)
		{
			for(int j=0;j<i;j++)
			{
				// if ith elem is greater then it should be adding to smaller length i.e las[1]
				if( a[i] > a[j] )
				{
					las[0][i] = max( las[0][i],las[1][j]+1 );
				}
				
				// if ith is smaller then it should add to the greater lenght i.e las[0]
				if( a[i] < a[j] )
				{
					las[1][i] = max( las[1][i],las[0][j]+1 );
				}
			}

		}
		int ans = max( las[0][n-1],las[1][n-1] );
		cout << ans << endl;
	}
}