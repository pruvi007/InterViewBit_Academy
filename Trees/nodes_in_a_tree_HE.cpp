/*
	NODES in A Tree
	HE
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;

struct node{
	int val;
	char c;
	node *left,*right;
	node(int val,char c)
	{
		this->val = val;
		this->c = c;
		this->left = NULL;
		this->right = NULL;
	}
};


void insert(node *root,int par,int child,char ch)
{
	if(root == NULL)
		return;
	if(root->val == par)
	{
		if(root->left == NULL)
			root->left = new node(child,ch);
		else
			root->right = new node(child,ch);
	}
	insert(root->left,par,child,ch);
	insert(root->right,par,child,ch);
}
node *find(node *root,int x)
{
	if(root == NULL)
		return NULL;
	if(root->val == x)
		return root;
	return find(root->left,x);
	return find(root->right,x);
}
int count_v = 0;
void count(node *root,char c)
{
	if(root == NULL)
		return;
	if(root->c == c)
		count_v++;
	count(root->left,c);
	count(root->right,c);

}

vector< vector<int> > v(100001);
bool vis[100001];

void bfs(int start,char ch,string s)
{
	queue<int> q;
	q.push(start);
	while(!q.empty())
	{
		int x = q.front();
		vis[x] = true;
		q.pop();
		if(s[x-1] == ch)
			count_v++;
		for(int i=0;i<v[x].size();i++)
		{
			if(vis[ v[x][i] ] == false)
				q.push(v[x][i]);
		}
	}
}
int main()
{
	int n,q;
	cin >> n >> q;
	string s;
	cin >> s;
	
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin >> x >> y;
		int par,child;
		par = x>y ? y:x;
		child = x>y ? x:y;
		v[par].push_back(child);
		
	}
	while(q--)
	{
		int x;
		char ch;
		cin >> x >> ch;
		
		count_v = 0;
		memset(vis,false,sizeof(vis));
		bfs(x,ch,s);
		cout << count_v << endl;
	}
}