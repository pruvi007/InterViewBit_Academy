/*
	remove duplicate letters and find lexicographically smallest
	Approach: find next smaller element and check whther the current elements can be scrapped off by their frquency.
	if a letter already in array occurs, ignore it
*/
// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin>>s;
	int n = s.length();
	stack<char> st;
	int present[26]={0};
	int freq[26]={0};
	for(int i=0;i<n;i++)
	{
		freq[s[i]%97]++;
	}
	// cout<<s<<endl;

	st.push(s[0]);
	present[s[0]%97]=1;
	// cout<<s<<endl;
	cout<<n<<endl;
	cout<<st.size()<<" ";
	for(int i=1;i<n;i++)
	{
		// cout<<st.size()<<" ";
		
		// cout<<" "<<s[i]<<" ";
		if(st.empty())
		{
			st.push(s[i]);
			present[s[i]%97]=1;
			continue;
		}
		else if(present[s[i]%97]==1)
		{
			freq[s[i]%97]--;
			continue;
		}
		else if(present[s[i]%97]==0 && s[i]>=st.top() )
		{
			st.push(s[i]);
			present[s[i]%97]=1;
		}
		else
		{
			while(!st.empty() && s[i]<st.top() && freq[st.top()%97]>1)
			{
				char x = st.top();
				present[x%97]=0;
				if(freq[x%97]>1)
					freq[x%97]--;
				else break;
				st.pop();
			}
			st.push(s[i]);
			present[s[i]%97]=1;
		}
	}
	// cout<<n<<endl;
	string ans = "";
	while(!st.empty())
	{
		ans += st.top();
		st.pop();
	}
	reverse(ans.begin(),ans.end());
	cout<<ans<<endl;

}