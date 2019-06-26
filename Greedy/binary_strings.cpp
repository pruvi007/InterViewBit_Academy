/*
    given a binary string and k;
    Flip consecutive k characters and try to make all 1's
    find minimums flips
    idea: find the 1st 0 and flip the next k chars and continue
*/
// solution by @pruvi007

int Solution::solve(string A, int B) {
    int n = A.length();
    int c = 0;
    for(int i=0;i<=n-B;i++)
    {
        if(A[i]=='0')
        {
            c++;
            for(int j=i;j<i+B;j++)
            {
                if(A[j]=='0')
                    A[j]='1';
                else A[j]='0';
            }
        }
    }
    int flag=0;
    for(int i=0;i<n;i++)
    {
        if(A[i]=='0')
            flag=1;
    }
    if(flag)
        return -1;
    return c;
}
