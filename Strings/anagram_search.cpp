/*
	given a string and a pattern. Find all occurences of anagram of pattern in text.
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;

// idea is to use sliding window and maintain a freq array

int main()
{
	string s,p;
	cin>>s>>p;
	int n = s.length();
	int m = p.length();
	int f[126] = {0};
	int f2[126] = {0};
	for(int i=0;i<m;i++)
		f[p[i]%126]++;

	for(int i=0;i<m;i++)
		f2[s[i]%126]++;

	int gf=0;
	for(int i=m;i<=n;i++)
	{
		int flag=0;
		for(int j=0;j<126;j++)
		{
			if(f[j]!=f2[j])
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			gf=1;
			cout<<(i-m)<<" ";
		}

		f2[s[i-m]%126]--;
		f2[s[i]%126]++;
	}
	cout<<endl;
	if(gf==0)
		cout<<"No Matches\n";
}