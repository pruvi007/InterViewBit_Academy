/*
	Find Diameter of the tree
	suppose the longest path passes through root so that length would be LH + RH + 1, do this for all roots and maintain the max
*/
// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node *left,*right;
    node(int val){
        this->val = val;
        this->left = this->right = NULL;
    }
};

node *insert(node *root,int k){
    if( root==NULL )
        return new node(k);
    if( root->val > k )
        root->left = insert(root->left,k);
    else 
        root->right = insert(root->right,k);
    return root;
}
int height(node *root){
    if( root==NULL )
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return 1+max(lh,rh);
}
int findD(node *root){
    if( root== NULL )
        return 0;
    // get heights of left and right subtree
    int lh = height(root->left);
    int rh = height(root->right);
    
    // get diamteres of left and right subtree
    int ld = findD(root->left);
    int rd = findD(root->right);
    
    // get the max diameter
    return max( lh+rh+1,max(ld,rd) );
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        node *root = NULL;
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
            root = insert( root,a[i] ); 
        }
        int d = findD(root);
        cout << d << endl;
        
    }
}