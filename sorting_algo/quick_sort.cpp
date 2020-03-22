#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &a,int l,int r)
{
    int pivot = a[r];
    int small = l-1;
    for(int i=l;i<r;i++)
    {
        if( a[i]<=pivot )
        {
            small++;

            // swap a[i] and a[small]
            int temp = a[i];
            a[i] = a[small];
            a[small] = temp;
        }
    }

    // swap a[small+1] and a[r]
    int temp = a[small+1];
    a[small+1] = a[r];
    a[r] = temp;

    cout << "Pivot: " << pivot << "-> ";
    for(int i=0;i<a.size();i++)
        cout << a[i] << " ";
    cout << endl;

    return small+1;
}
void quickSort(vector<int> &a,int n,int l,int r)
{
    if(l<r)
    {
        int p = partition(a,l,r);
        quickSort(a,n,l,p-1);
        quickSort(a,n,p+1,r);
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];
    quickSort(a,n,0,n-1);
    for(int i=0;i<n;i++)
        cout << a[i] << " ";
    cout << endl;
}