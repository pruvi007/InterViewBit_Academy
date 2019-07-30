/*
	BEST TIME TO SELL STOCKS 2
	idea: add up all peaks and valleys that occur in the array (in this manner you will always maximize the profit)
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++)
		cin >> a[i];
	int j = 0;
    int valley = a[0];
    int peak = a[0];
    int maxprofit = 0;
    while (i < n - 1) {
        while (i < n - 1 && a[i] >= a[i + 1])
            i++;
        valley = a[i];
        while (i < n - 1 && a[i] <= a[i + 1])
            i++;
        peak = a[i];
        maxprofit += peak - valley;
    }
    return maxprofit;

}