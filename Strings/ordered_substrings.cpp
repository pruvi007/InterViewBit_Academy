/*
	Ordered Substrings

	Input:
	A: [abc, abcd, a, abc]

	Output:
	[a, abc, abc, abcd]

	Input:
	A: [xyz, xz, xyzzy]

	Output:
	[NO]
*/
// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<pair<int,string> > s;
	for(int i=0;i<n;i++)
	{
		string x;
		cin>>x;
		s.push_back({x.length(),x});
	}
	sort(s.begin(),s.end());
	int substr = 0;
	for(int i=1;i<n;i++)
	{

		

		string text = s[i].second;
		string p = s[i-1].second;
		int l1 = text.length();
		int l2 = p.length();

		// create LPS - longest prefix suffix array
		int lps[l2];
		lps[0] = 0;
		int l=0,r=1;
		while(r<l2)
		{
			if(p[l]==p[r])
			{
				l++;
				lps[r] = l;
				r++;
			}
			else
			{
				if(l!=0)
					l = lps[l-1];
				else
				{
					lps[r] = 0;
					r++;
				}
			}
		}

		// now do KMP
		int flag=0;
		l=0;r=0;
		while(l<l1)
		{
			if(text[l] == p[r])
			{
				l++;
				r++;
			}
			if(r==l2)
			{
				flag=1;
				break;
			}
			else if(l<l1 && text[l]!=p[r])
			{
				if(r!=0)
					r = lps[r-1];
				else
					l++;

			}
		}
		if(flag==0)
		{
			substr=1;
			break;
		}

	}
	if(substr==1)
		cout<<"NO\n";
	else
	{
		for(int i=0;i<n;i++)
		{
			cout<<s[i].second<<" ";
		}
		cout<<endl;
	}
}