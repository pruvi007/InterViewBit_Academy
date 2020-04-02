int x;
bool compare(int a,int b)
{
    return a%x<b%x or(a%x==b%x and a<b);
}
void StayHomeTask(int arr[], int n, int k)
{
    x = k;
    sort(arr,arr+n,compare);
    for(int i=0;i<n;i++)
        cout << arr[i] << " ";
}