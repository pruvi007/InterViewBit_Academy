/*
    handle - pruvi007
    questionName - 
    Contest - 
    Topic - 
    Platform - 
*/
#include<bits/stdc++.h>
using namespace std;
#define ll          long long int
#define fast         ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define INF          1e18
#define MOD          1000000007
#define Vi           vector<ll> 
#define Vs           vector<string>
#define VI           vector<vector<ll> >
#define PII          pair<ll,ll> 
#define PSI          pair<string,ll>
#define PB           push_back


int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};
int DX[] = {0,-1,-1,-1,0,1,1,1};
int DY[] = {-1,-1,0,1,1,1,0,-1};

int main()
{
    fast;
    ll t;
    cin >> t;
    ll mod = 1e9 + 7;
    while(t--)
    {
        ll n;
        cin >> n;
        ll a[n];
       
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
        }

        //pge and nge
        stack<pair<int,int> > s;
		int nge[n]={-1};
		s.push({a[0],0});
		for(int i=1;i<n;i++)
		{
			

			pair<int,int> x = s.top();

			if(a[i]<=x.first)
			{
				s.push({a[i],i});
			}
			else
			{

				while(!s.empty() && a[i]>s.top().first)
				{

					nge[s.top().second] = i;
					s.pop();

				}
				s.push({a[i],i});
			}
		}
		while(!s.empty())
		{
			pair<int,int> p = s.top();
			nge[p.second] = n-1;
			s.pop();
		}

		// for(int i=0;i<n;i++)
		// 	cout<<nge[i]<<" ";
		// cout<<endl;


		int pge[n]={-1};
		s.push({a[n-1],n-1});
		for(int i=n-2;i>=0;i--)
		{

			pair<int,int> x = s.top();

			if(a[i]<=x.first)
			{
				s.push({a[i],i});
			}
			else
			{

				while(!s.empty() && a[i]>s.top().first)
				{

					pge[s.top().second] = i;
					s.pop();

				}
				s.push({a[i],i});
			}
		}
		while(!s.empty())
		{
			pair<int,int> p = s.top();
			pge[p.second] = 0;
			s.pop();
		}

		// for(int i=0;i<n;i++)
		// 	cout<<pge[i]<<" ";
		// cout<<endl;
		ll M = -1;
		ll ind ;
		for(int i=0;i<n;i++)
		{
			ll A = i-pge[i] + nge[i]-i;
			ll B = (i+1);
			ll p = (A%mod * B%mod)%mod;
			if(p>M)
			{
				M = p;
				ind = i;
			}
		}

        cout << ind+1 << '\n';  
        
    }
}