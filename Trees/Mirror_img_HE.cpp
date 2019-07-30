/*
	mirror image Hacker Earth
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;

struct node{
	int val;
	node *left,*right;
	node(int val)
	{
		this->val = val;
		this->left = NULL;
		this->right = NULL;
	}
};

void insert(node *root,int p,int n,char c)
{
	if(root == NULL)
		return;
	if(root->val == p)
	{
		node *temp = new node(n);
		if(c=='L')
			root->left = temp;
		else root->right = temp;
	}
	insert(root->left,p,n,c);
	insert(root->right,p,n,c);
}

int h = 0;
vector< pair<int,int> > level(node *root)
{
	vector< pair<int,int> > l1;
	queue< pair<node *,int> > q;
	q.push({root,0});
	l1.push_back({root->val,h});
	while(!q.empty())
	{
		int n = q.size();
		for(int i=0;i<n;i++)
		{
			pair<node *,int> x = q.front();
			q.pop();
			h = x.second;
			int flag=0;
			if(x.first->left)
			{
				flag=1;
				q.push({x.first->left,x.second+1});
			}
			if(x.first->right)
			{
				flag=1;
				q.push({x.first->right,x.second+1});
			}
			
			l1.push_back({x.first->val,x.second});
			
			// cout << x.first->val << " ";
		}
		// cout << endl;
	}
	return l1;
}

map<int,int> m;
int mirror(node *a,node *b,int k)
{
	if(a == NULL || b==NULL)
		return -1;

	if(a->val == k)
		return b->val;
	if(b->val == k)
		return a->val;

	int m_val = mirror(a->left,b->right,k);
	if(m_val)
		return m_val;
	mirror(a->right,b->left,k);


}
int main()
{
	int n,q;
	cin >> n >> q;
	node *root = NULL;
	root = new node(1);
	for(int i=0;i<n-1;i++)
	{
		int x,y;
		char c;
		cin >> x >> y >> c;
		insert(root,x,y,c);
	}
	vector<pair<int,int> > a = level(root);
	
	while(q--)
	{	
		int x;
		cin >> x;
		if(x==1)
			cout << x << endl;
		else
		{
			int ans = mirror(root->left,root->right,x);
			cout << ans << endl;
		}
		
		
	}
	


}