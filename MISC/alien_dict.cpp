#include<bits/stdc++.h>
using namespace std;

map< char,vector<char> > mp;
set<int> st;

void topological(vector<vector<int> > &v,int inDegree[],int size)
{
	// get the list of nodes with indegree 0
	queue<int> q;
	for(int i=0;i<26;i++)
	{
		if( st.find(i)!=st.end() )
		{
			if( inDegree[i] == 0)
				q.push(i);
		}
	}

	// visited vertices
	int vis = 0;
	vector<int> top_order;
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		top_order.push_back(x);
		
		for(int i=0;i<v[x].size();i++)
		{
			inDegree[v[x][i]]--;
			if( inDegree[v[x][i]] == 0 )
				q.push(v[x][i]);
		}
		vis++;

	}
	// cout << vis << " " << size;
	if( vis!=size )
	{
		cout << "Invalid" << endl;
	}
	else
	{
		for(int i=0;i<top_order.size();i++)
		{
			char ch = char(top_order[i]+97);
			cout << ch ;
		}
		cout << endl;
	}

}

int main()
{
	int n;
	cin >> n;
	string s[n];
	
	for(int i=0;i<n;i++)
	{
		cin >> s[i];
		for(int j=0;j<s[i].length();j++)
		{
			st.insert(s[i][j]%97);
		}
	}
	int size = st.size();
	vector< vector<int> > v(26);
	int inDegree[26]={0};
	for(int i=1;i<n;i++)
	{
		string a = s[i-1];
		string b = s[i];
		int l1 = a.length(), l2 = b.length();
		for(int j=0;j<min(l1,l2);j++)
		{
			if( a[j] != b[j] )
			{
				int c1 = a[j]%97;
				int c2 = b[j]%97;
				v[c1].push_back(c2);
				inDegree[c2]++;
				break;
			}
		}

	}
	topological(v,inDegree,size);
}