/*
	Find the min time to complete n tasks where you can skip any task but cant skip 2 consecutive tasks
*/
// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;

int skip(int a[],int n){

	int inc[n+1],exc[n+1];
	inc[0] = a[0]; //include 0th task
	exc[0] = 0;    //exclude 0th task
	for(int i=1;i<n;i++)
	{
		// include the ith item 
		inc[i] = a[i] + min(inc[i-1],exc[i-1]);
		// exclude the ith item and take prev include
		exc[i] = inc[i-1];
	}
	return min(inc[n-1],exc[n-1]);
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n];
		for(int i=0;i<n;i++)
			cin >> a[i];
		int ans  = skip(a,n);
		cout << ans << endl;
	}
}