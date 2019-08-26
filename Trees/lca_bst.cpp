#include<bits/stdc++.h>
using namespace std;

struct bst{
    int val;
    bst *left,*right;
    bst(int val){
        this->left = this->right = NULL;
        this->val = val;
    }
};

bst *insert(bst *root,int k){
    if( root==NULL )
        return new bst(k);
    if( root->val > k )
        root->left = insert(root->left,k);
    else 
        root->right = insert(root->right,k);
    
    return root;
}

bst *bstLca(bst *root,int n1,int n2){
    if( root==NULL )
        return NULL;
    if( root->val == n1 || root->val == n2)
        return root;

    // property of bst
    if( (root->val > n1 and root->val < n2) or (root->val < n1 and root->val > n2) )
        return root;

    // lca is in left subtree
    if( root->val > n1 and root->val > n2 )
        return bstLca(root->left,n1,n2);

    // lca is in right subtree
    return bstLca(root->right,n1,n2);
}
int main(){
    int t;
    cin >> t;
    while(t--)
    {
        int n,q;
        cin >> n >> q;
        bst *root = NULL;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
            root = insert( root,a[i] );
            
        }
        while(q--)
        {
            int n1,n2;
            
            cin >> n1 >> n2;
            bst *lca = bstLca(root,n1,n2);
            if(lca)
                cout << lca->val << " ";
            
        }
        cout << endl;
        
    }
}