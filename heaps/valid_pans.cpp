#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	getline(cin, s); 
	// cout<<s<<endl;
	int l = s.length();
	char a[11];
	if(l<10)
		cout<<0<<endl;
	else
	{
		
		
		int count = 0;
		
		map<string,int> mp;
		for(int i=0;i<l;i++)
		{
			int ca = 0;
			for(int j=i;j<i+10;j++)
			{

				a[ca++] = s[j];
			}
			// for(int j=0;j<10;j++)
			// {
				
			// 	cout<<a[j];
			// }
			// cout<<endl;
			int flag=0;
			int c =0;
			int fourth = 0;
			int fifth=0;

			// 1st 5 letters alapha
			for(int j=0;j<5;j++)
			{
				if((a[j]>='A' && a[j]<='Z'))
				{
					if(c==3)
					{
						if(a[c]=='A' || a[c]=='B' || a[c]=='C' || a[c]=='F' || a[c]=='G' || a[c]=='H' || a[c]=='L' || a[c]=='J' || a[c]=='P' || a[c]=='T' || a[c]=='K')
						{
							fourth = 1;
						}
					}
					if(c==4)
					{
						if(a[c]==a[c-4])
						{
							fifth=1;
						}
					}
					
				}
				else
				{
					flag=1;
					break;
				}
				c++;
			}
			// then 4 numbers
			for(int j=5;j<9;j++)
			{
				if(a[j]>='0' && a[j]<='9')
				{
					continue;
				}
				else
				{
					flag=1;
					break;
				}
			}
			// then alpha
			if(a[9]<'A' || a[9]>'Z')
				flag=1;

			if(flag==0 && (fourth==1 && fifth==1))
			{
				string temp="";
				for(int j=0;j<10;j++)
				{
					temp+=a[j];
					// cout<<a[j];
				}
				// cout<<endl;
				if(mp.find(temp)==mp.end())
				{
					count++;
					mp[temp]++;
				}
				
			}

		}
		
		cout<<count<<endl;
	}
	
}
