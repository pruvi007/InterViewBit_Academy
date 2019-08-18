/*
	Bus Passengers
	Make MinHeap for given 0's and the zeros which go on filling make a MaxHeap out of it
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;

#define ll long long int 

struct myCompm{
	bool operator()(pair<int,int> a,pair<int,int> b)
	{
		return a.first > b.first;
	}
};

struct myCompM{
	bool operator()(pair<int,int> a,pair<int,int> b)
	{
		return a.first < b.first;
	}
};
int main(){
	int n;
	cin >> n;
	int a[n];
	// minHeap
	priority_queue< pair<int,int>, vector<pair<int,int>>, myCompm> m;
	// maxHeap
	priority_queue< pair<int,int>, vector<pair<int,int>>, myCompM> M;

	for(int i=0;i<n;i++)
	{
		cin >> a[i];
		m.push({a[i],i+1});
	}
	// while(!m.empty()){
	// 	pair<int,int> p = m.top();
	// 	m.pop();
	// 	cout << p.first << " " << p.second << endl;
	// }
	string s;
	cin >> s;
	int l = s.length();
	for(int i=0;i<l;i++)
	{
		if(s[i] == '0')
		{
			pair<int,int> p = m.top();
			m.pop();
			cout << p.second << " ";
			M.push({p.first,p.second});
		}
		else
		{
			pair<int,int> p = M.top();
			M.pop();
			cout << p.second << " ";
		}
	}
	cout << endl;

}