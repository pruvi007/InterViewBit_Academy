#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0;i<n;i++)
		cin >> a[i];
	vector<int> left(n,0),right(n,0);
	int l = 1;
	left[0] = 1;
	for(int i=1;i<n;i++)
	{
		if(a[i]>a[i-1])
		{
			l++;
			left[i] = max(left[i],l);
		}
		else{
			l=1;
			left[i] = max(left[i],l);
		}
	}
	right[n-1] = 1;
	l = 1;
	for(int i=n-2;i>=0;i--)
	{
		if(a[i+1]>a[i])
		{
			l++;
			right[i] = max(right[i],l);
		}
		else{
			l=1;
			right[i] = max(right[i],l);
		}
	}
	for(int i=0;i<n;i++)
		cout << left[i] << " ";
	cout << endl;
	for(int i=0;i<n;i++)
		cout << right[i] << " ";
	cout << endl;
}