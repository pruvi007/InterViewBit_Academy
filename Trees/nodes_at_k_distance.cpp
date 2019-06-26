/*
	Find all nodes at k distacne from a given node.
	(will use parent approach and a queue for BFS)
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

map<node *,node *> m;
map<node *,int> seen;
node *s = NULL;
void mark_parents(node *root)
{
	if(root==NULL)
		return ;
	if(root->left)
		m[root->left] = root;
	if(root->right)
		m[root->right] = root;

	mark_parents(root->left);
	mark_parents(root->right);
}

void search(node *root,int k)
{
	if(root!=NULL)
	{
		search(root->left,k);
		if(root->val == k)
		{
			s = root;
			return ;
		}
		search(root->right,k);
	}

}

void *k_distance(node *start,int k)
{
	queue<node *> q,temp;
	q.push(start);
	int c = 0;
	seen[start]++;

	while(!q.empty())
	{
		int n = q.size();
		temp = q;
		if(c == k)
		{
			while(!q.empty())
			{
				node *x = q.front();
				cout << x->val << " ";
				q.pop();
			}
			cout << endl;
			break;
		}
		for(int i=0;i<n;i++)
		{
			node *x = q.front();
			q.pop();
			node *p = NULL;
			if(m.find(x)!=m.end())
				p = m[x];
			
			if(x->left && seen.find(x->left)==seen.end())
			{
				q.push(x->left);
				seen[x->left]++;
			}
			if(x->right && seen.find(x->right)==seen.end())
			{
				q.push(x->right);
				seen[x->right]++;
			}
			if(p!=NULL && seen.find(p)==seen.end())
			{
				q.push(p);
				seen[p]++;
			}

		}
		c++;
	}
}
int main()
{
	node *root = new node(94);
	root->left = new node(91);
	root->right = new node(21);
	root->left->left = new node(2);
	root->left->right = new node(24);
	root->right->right = new node(51);
	root->right->left = new node(46);
	root->left->left->left = new node(78);
	root->left->right->right = new node(55);

	m.clear();
	mark_parents(root);
	map<node *,node *>::iterator it;
	for(it=m.begin();it!=m.end();it++)
	{
		cout << (it->first->val) << ": " << (it->second->val) << endl;
	}

	int val;
	cin>>val;
	search(root,val);
	cout << "Found: " << s->val <<endl;
	int k;
	cin>>k;
	k_distance(s,k);

}