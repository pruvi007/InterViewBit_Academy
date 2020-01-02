#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+1;

int M = 0;
bool bought[MAXN];
void solve( int a[],int n,int level,int item,int rem,int k )
{
    if( rem < 0 )
        return ;
    if( level == -1)
    {
        M = max( M,item );
        return;
    }
    // if he buys the current item
    if( a[level] <= rem and bought[level]==false)
    {
        // then select k-1 elements for the same price
        int c = 0;
        bought[level] = true;
        bool ableToChoose = false;
        for(int i=0;i<n;i++)
        {
            if( i!=level )
            {
                if( a[i] <= rem and bought[i]==false )
                {
                    bought[i] = true;
                    c++;
                    if( c==k-1 )
                    {
                        ableToChoose = true;
                        break;
                    }
                        
                }
            }
        }
        int more = 1;
        if(ableToChoose)
            more = k;
        solve( a,n,level+1,item+more,rem-a[level],k );
    }
    else
    {
        solve( a,n,level+1,item,rem,k );
    }
    
    
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,p,k;
        cin >> n >> p >> k;
        int a[n];
        for(int i=0;i<n;i++)
            cin >> a[i];
        sort(a,a+n);
        
        memset( bought,false,sizeof(bought) );
        M = 0;
        solve( a,n,n-1,0,p,k );
        cout << M << endl;
        
    }
}