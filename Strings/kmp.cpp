/*
	perform KMP string matching algorithm
*/
// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;
int main()
{
	string text,p;
	cin>>text>>p;
	int n = text.length();
	int m = p.length();
	int lps[m];
	lps[0] = 0;
	int l=0,r=1;
	while(r<m)
	{
		if(p[l]==p[r])
		{
			l++;
			lps[r] = l;
			r++;
		}
		else
		{
			if(l>0)
				l = lps[l-1];
			else
			{
				lps[r] = 0;
				r++;
			}

		}
	}

	for(int i=0;i<m;i++)
		cout<<lps[i]<<" ";
	cout<<endl;

	// start matching. If matched then fine else skip chars according to LPS.
	l=0;r=0;
	int ind = -1;
	while(l<n)
	{
		if(text[l] == p[r])
		{
			l++;
			r++;
		}
		if(r==m)
		{
			ind = abs(r-l);
			// to find all occurences of the pattern, uncomment the following
			// j = lps[j-1];
			break;
		}
		else if(l<n && text[l]!=p[r])
		{
			if(r!=0)
				r = lps[r-1];
			else
				l++;
		}
	}
	cout<<ind<<endl;
}
