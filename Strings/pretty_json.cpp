// conver the given json to its pretty form

// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	vector<string> v;
	int l = s.length();
	for(int i=0;i<l;)
	{
		if(s[i]=='[' || s[i]=='{' || s[i]=='}' || s[i]==']')
		{
			string temp = s[i]+"\n";
			v.push_back(temp);
			i++;
		}
		else
		{
			string temp = "\t";
			while(s[i]!=',' || s[i]!='[' || s[i]!='{' || s[i]=='}' || s[i]==']')
			{
				temp+=s[i];
			}
			temp+=
		}
	}
}