/*
    STACKING CUBES
    idea; no of factors -1
*/

int Solution::solve(int A) {
    int f = 0;
    for(int i=1;i<=sqrt(A);i++)
    {
        if(A%i==0)
        {
            if(A/i!=i)
                f+=2;
            else f++;
        }
    }
    return f-1;
    
}
