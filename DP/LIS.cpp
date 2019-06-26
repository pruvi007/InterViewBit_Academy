/*
	LIS
	for j = to i
	check if a[i] > a[j] then update the LIS count
*/
// solution by @pruvi007
int Solution::lis(const vector<int> &a) {
    // LIS
    // idea to traver from 0 to i and keep updating the LIS array
    int n = a.size();
    int lis[n];
    lis[0]=1;
    for(int i=1;i<n;i++)
    {
        lis[i]=1;
        // updation of the LIS array if a[i] is greater
        for(int j=0;j<i;j++)
        {
            if(a[i]>a[j])
            {
                lis[i] = max(lis[i],lis[j]+1);
            }
        }
    }
    sort(lis,lis+n);
    return lis[n-1];
}
