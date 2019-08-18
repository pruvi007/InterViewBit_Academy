/*
    Get the final sum of all root to leaf paths
    get all the paths in one pre order traversal.
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll mod = 1e9+7;
struct node{
    int val;
    node *left,*right;
    node(int data)
    {
        this->val = data;
        this->left = NULL;
        this->right = NULL;
    }
};
node *insert(node *root,int x)
{
    if(root==NULL)
        return new node(x);
    if(root->val > x)
        root->left = insert(root->left,x);
    else
        root->right = insert(root->right,x);
    return root;
}

// gets all the paths from 1 pre order traversal.
vector<int> temp;
vector<vector<int> > v;
void getPath(node *root)
{
    if(root==NULL)
        return;
    temp.push_back(root->val);
    if(root->left==NULL && root->right==NULL)
    {
        v.push_back(temp);
    }
    getPath(root->left);
    getPath(root->right);
    temp.pop_back();
    
    
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        node *root = NULL;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            root = insert(root,a[i]);
        }
        temp.clear();
        v.clear();
        getPath(root);
        ll sum = 0;
        
        for(int i=0;i<v.size();i++)
        {
            ll n = 0;
            string s= "";
            for(int j=0;j<v[i].size();j++)
            {
                // cout<<v[i][j]<<" ";
                s += to_string(v[i][j]);
            }
            ll l = s.length();
            ll s2 = 0;
            for(int j=0;j<l;j++)
            {
                s2= s2*10 + (s[j]-'0');
                s2 %= mod;
            }
            sum = (sum + s2)%mod;
            
        }
        cout<<sum<<endl;
    }
}