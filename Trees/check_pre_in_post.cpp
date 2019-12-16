int find(int in[],int l,int r,int x)
{
	for(int i=l;i<=r;i++)
	{
		if(in[i] == x)
			return i;
	}
	return -1;
}

TreeNode *build(int pre[],int in[],int l,int r,int level)
{
	if(r<l)
		return NULL;
	
	TreeNode *n = new TreeNode(pre[level]);
	level++;
	if(l==r)
		return n;
	int pos = find(in,l,r,n->val);
	TreeNode *lst = build(pre,in,l,pos-1,level);
	TreeNode *rst = build(pre,in,pos+1,r,level);
	n->left = lst;
	n->right = rst;
	return n;
}