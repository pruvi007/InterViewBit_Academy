#define ll long long int
ll mod = 1e9+7;
int tree[500005];

void build(int a[],int l,int r,int pos)
{
	if(l==r)
	{
		tree[pos] = a[l];
		return;
	}
	int mid = (l+r)/2;
  
	// left child
	build(a,l,mid,2*pos+1);
	// right child
	build(a,mid+1,r,2*pos+2);
  	//adding so that we get total no of set bits 
	tree[pos] = tree[pos*2+1]+tree[pos*2+2];
}
void update_Range(int ql,int qe,int l,int r,int pos)
{
  	//using update in Range because xor over a range will toggle many values
  	//invalid range
	if(l>r || ql>r || qe<l)
		return ;
	if(l==r)
	{
      	//do the xor
		tree[pos] = tree[pos]^1;
		return ;	
	}
	int mid = (l+r)/2;
  	//search for left child
	update_Range(ql,qe,l,mid,2*pos+1);
  	//search for the right child
	update_Range(ql,qe,mid+1,r,2*pos+2);
  	//add the updated no. of set bits
	tree[pos] = tree[2*pos+1] + tree[2*pos+2];
}
int query(int l,int r,int ql,int qe,int pos)
{
	if(ql<=l && qe>=r)
		return tree[pos];
	if(ql>r || qe<l)
		return 0;
	int mid = (l+r)/2;
	return query(l,mid,ql,qe,2*pos+1) + query(mid+1,r,ql,qe,2*pos+2);
}

int Solution::solve(int A, vector<vector<int> > &B) {
    
    int a[A+1];
    for(int i=0;i<=A;i++)
        a[i]=0;
    build(a,0,A,0);
    ll sum = 0;
    for(int i=0;i<B.size();i++)
    {
        
            int t,l,r;
            t = B[i][0];
            l = B[i][1];
            r = B[i][2];
            if(t==0)
            {
              	//update the range
                update_Range(l,r,0,A-1,0);
            }
            else
            {
              	//get the sum over the range and add final ans
                ll ans = query(0,A-1,l,r,0);
                sum = (sum%mod + ans%mod)%mod;
            }
        
    }
    return sum%mod;
}