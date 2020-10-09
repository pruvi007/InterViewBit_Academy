int Solution::solve(vector<vector<int> > &A, int B) {
    int n,m;
    n = A.size();m = A[0].size();
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<m;j++)
            A[i][j] += A[i][j-1];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<m;j++)
            A[i][j] += A[i-1][j];
    }
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<m;j++)
    //         cout << A[i][j] << " ";
    //     cout << '\n';
    // }
    int low=1,high = min(n,m);
    int ans = -1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        bool valid = true;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int sx = i;
                int sy = j;
                int ex = i+mid-1;
                int ey = j+mid-1;
                if( ex<n and ey<m )
                {
                    int s = A[ex][ey];
                    if( sy-1>=0 )
                        s -= A[ex][sy-1];
                    if(sx-1>=0)
                        s-= A[sx-1][ey];
                    if(sx-1>=0 and sy-1>=0)
                        s += A[sx-1][sy-1];
                    // cout << mid << ": " << s << '\n';
                    if(s>B)
                    {
                        valid = false;
                        break;
                    }
                        
                }
            }
            if(valid == false)
                break;
        }
        if(valid)
        {
            ans = mid;
            low = mid+1;
        }
        else high = mid-1;
    }
    
    return ans;
}
