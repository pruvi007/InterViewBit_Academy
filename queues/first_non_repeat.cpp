/*
	print first non-repeat character in stram of characters.
	approach: use queue. whenever the incoming character's freq becomes 2 pop from queue and print front.
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int n = s.length();
	queue<char> q;
	int freq[26]={0};
	char a[n];
	int ca = 0;
	for(int i=0;i<n;i++)
	{
		freq[s[i]%97]++;
		if(freq[s[i]%97]==1)
			q.push(s[i]);

		// elements whose freq has increased more than 1. pop it
		while(!q.empty() && freq[q.front()%97]>1)
		{
				q.pop();
		}

		if(q.size()>0)
		{
			a[ca++] = q.front();
		}
		else a[ca++] = '#';
		
	}
	a[ca] = '\0';
	string ans;
	ans = a;
	cout<<ans<<endl;
}