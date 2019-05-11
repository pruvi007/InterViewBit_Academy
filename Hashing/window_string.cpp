#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin>>s;
	string p;
	cin>>p;
	int f1[260] = {0};
	int f2[260] = {0};
	int l1 = s.length();
	int l2 = p.length();
	for(int i=0;i<l2;i++)
	{
		f2[p[i]%260]++;
	}

	int l= 0,r=0;
	f1[s[0]%260]++;
	// f1[s[1]%260]++;
	int min = INT_MAX;
	int xl=-1,xr=-1;
	while(l<=r && r<l1)
	{
		int f = 0;
		for(int i=0;i<260;i++)
		{
			if(f1[i]<f2[i])
			{
				f=1;
				break;
			}
		}
		if(f==1)
		{
			r++;
			f1[s[r]%260]++;

		}
		else
		{
			if((r-l+1)<min)
			{
				min = r-l+1;
				xl = l;
				xr = r;
			}
			f1[s[l]%260]--;
			l++;

		}
	}
	if(xl!=-1 && xr!=-1)
	{
		cout<<min<<endl;
		for(int i=xl;i<=xr;i++)
			cout<<s[i];
		cout<<endl;
	}
	else
	{
		cout<<"-1\n";
	}
	

}