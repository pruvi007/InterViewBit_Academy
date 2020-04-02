bool valid(int h,int a[],int n)
{
    int c = 0;
    int m = -1;
    for(int i=0;i<n;i++)
    {
        if(a[i]>=h)
            c++;
    }
    
    if(c>=h)
        m = max(c,m);
    // cout << h << ": " << m << endl;
    if(m>=h)
        return true;
    return false;
}
int maxArea(int arr[], int n) 
{ 
    
    int low = 1,high = *max_element(arr,arr+n);
    int ans;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(valid(mid,arr,n))
        {
            ans = mid;
            low = mid+1;
        }
        else
            high = mid-1;
    }
    return ans*ans;
    
} 