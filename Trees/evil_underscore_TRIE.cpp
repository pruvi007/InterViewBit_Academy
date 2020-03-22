#include<bits/stdc++.h>
using namespace std;

#define ll long long int

struct trieNode{
    trieNode *left,*right;
    trieNode()
    {
        this->left = this->right = NULL;
    }
};
trieNode *root = NULL;

void insert( ll x )
{
    if( root==NULL )
        root = new trieNode();

    trieNode *temp = root;
    for(int i=31;i>=0;i--)
    {
        ll bit = x & (1 << i );
        if( bit==0 )
        {
            if( temp->left == NULL )
                temp->left = new trieNode();
            temp = temp->left;
        }
        else
        {
            if( temp->right==NULL )
                temp->right = new trieNode();
            temp = temp->right;
        }
        
    }
    return;
}
ll query( ll x )
{
    trieNode *temp = root;
    ll ans = 0;
    for(int i=31;i>=0;i--)
    {
        ll bit = x & (1 << i );
        if( bit==0 )
        {
            if( temp->right )
            {
                ans += 1<<i;
                temp = temp->right;
            }
            else 
                temp = temp->left;
        }
        else
        {
            if( temp->left )
            {
                ans += 1<<i;
                temp = temp->left;
            }
            else   
                temp = temp->right;
        }
        
    }
    return ans;
}
int main()
{
    int n;
    cin >> n ;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        insert( a[i] );
    }
    int ans = 0, m = INT_MAX;
    for(int i=0;i<=31;i++)
    {
        int q = query( i );
        if( q<m )
        {
            m = q;
            ans = i;
        }
    }
    // cout << "At : " << ans << endl;
    cout << m << endl;

}