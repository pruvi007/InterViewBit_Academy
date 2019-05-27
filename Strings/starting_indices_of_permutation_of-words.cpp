/*
	Given a string A and list of words B(words in B are of same length). Find and return the starting 
	indices of the substrings in string A, which contains all the words present in list B. 
	Note:
	The order of words of list B appearing inside string S does not matter.
	Words inside the list B can repeat.
*/
// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	
	int n;
	cin>>n;

	vector<string> p;
	map<string,int> m;
	int win = 0;
	for(int i=0;i<n;i++)
	{
		string x;
		cin>>x;
		win += x.length();
		p.push_back(x);
		m[x]++;
	}

	int k = win/n;
	for(int i=0;i<s.length();i++)
	{
		string temp="";
		map<string,int> temp_map;
		if(i+win<=s.length())
		{
			for(int j=i;j<i+win;j++)
			{
				temp += s[j];
				if(temp.length()==k)
				{
					// cout<<"\n"<<temp<<" ";
					temp_map[temp]++;
					temp = "";
				}

			}

			// cout<<endl;
			map<string,int>::iterator it1,it2;
			it2 = temp_map.begin();
			int flag=0;
			for(it1=m.begin();it1!=m.end();it1++)
			{
				// cout<<it1->first<<" "<<it1->second <<" : "<<it2->first<<" "<<it2->second<<endl;
				if(it1->first == it2->first && it1->second == it2->second)
				{

					advance(it2,1);
					continue;
				}
				else
				{
					flag=1;
					break;
				}
			}
			if(flag==0)
				cout<<i<<" ";
			temp_map.clear();
		}
		else break;
		
		

	}
	cout<<endl;

	


}