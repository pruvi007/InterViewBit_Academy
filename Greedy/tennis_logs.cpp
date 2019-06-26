
/*
    Tennis Logs
    Find if winners are valid.
    Idea; Keep track of spectator each time and check if winner is not spectator.
*/
// solution by @pruvi007

string Solution::solve(int k, vector<int> &a) {
    int n = a.size();
    if(n==1)
    {
        if(a[0]==1 || a[0]==2)
            return "Yes";
        return "No";
    }
    else
    {
        if(a[0]==3)
            return "No";
        int s=6-a[0]-3,w = a[0];
        for(int i=1;i<n;i++)
        {
            if(a[i]==s)
            {
                return "No";
            }
            s = 6 - a[i] - s;
                
        }
        return "Yes";
    }
    
}
