#include<bits/stdc++.h>
using namespace std;


int isPalindrome(string s,int st,int end)
{
	int f=0;
	int low = st,high=end;
	while(low<high)
	{
		if(s[low]!=s[high])
		{
			return 0;
		}
		low++;
		high--;
	}
	return 1;
}
void partition(vector<string> &curr, string s,int level)
{
	static string pal = "";
	if(level>=s.length())
	{
		for(int i=0;i<curr.size();i++)
			cout<<curr[i]<<" ";
		cout<<endl;
		return ;
	}

	for(int i=level;i<s.length();i++)
	{
		if(isPalindrome(s,level,i))
		{
			curr.push_back(s.substr(level,i-level+1));
			partition(curr,s,i+1);
			curr.pop_back();
		}
	}
	
}
int main()
{
	string s;
	cin>>s;
	vector<string> curr;
	partition(curr,s,0);
	
}