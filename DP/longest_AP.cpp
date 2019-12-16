
/*
    dp state:
    dp[i][d] = longest AP sequence from (0..i) with difference d
*/
int Solution::solve(const vector<int> &a) {
    unordered_map<int,int> mp[2000];
    int ret = 0;
    int n = a.size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            int d = a[i]-a[j];
            mp[i][d] = mp[j][d]+1;
            ret = max(ret,mp[i][d]);
        }
    }
    return ret+1;
}