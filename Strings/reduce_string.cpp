// Find and return the string by reducing it to its shortest length. if the resultant string is empty return "empty"
// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;

	int n = s.length();
	while(1)
	{
		int flag=0;
		string temp = "";
		for(int i=0;i<s.length();)
		{
			if(s[i]==s[i+1])
			{
				i+=2;
				flag=1;
			}
			else
			{
				temp += s[i];
				i++;
			}
		}
		if(flag==0)
			break;
		s = temp;

	}
	if(s.length() == 0)
		cout<<"EMPTY\n";
	else cout<<s<<endl;
}