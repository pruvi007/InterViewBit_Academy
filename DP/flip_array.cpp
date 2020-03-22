#define ll long long int

struct bag{
    int val;
    int item;
   
}dp[101][10001];
int flip(vector<int> a)
{
    int n = a.size();
    ll sum = 0;
	for(int i=0;i<n;i++)
		sum += a[i];

	
	for(int i=0;i<=sum;i++)
	{
		for(int j=0;j<=n;j++)
		{
		    if(i==0 or j==0)
		    {
		        dp[i][j].val = 0;
		        dp[i][j].item = 0;
		    }
			if(a[j-1]<=i)
			{
			    int cur_val = a[j-1] + dp[i-a[j-1]][j-1].val;
			    int cur_item = dp[i-a[j-1]][j-1].item+1;
				if(cur_val > dp[i][j-1].val or (cur_val == dp[i][j-1].val and cur_item<dp[i][j-1].item) )
				{
					dp[i][j].val = cur_val;
					dp[i][j].item = cur_item;
				}
				else 
					dp[i][j] = dp[i][j-1];
					
			}
			else
				dp[i][j] = dp[i][j-1];
		}
	}
	int ans = dp[sum/2][n].item;
    return ans;
}
int Solution::solve(const vector<int> &A) {
    return flip(A);
}
