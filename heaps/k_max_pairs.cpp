/*
    find k-max pairs sum frmo two sorted arrays.
    Idea: to use a max heap to get the idea of next max pair
    will build various classes to implement triplet priority queue 
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;

#define ll long long int
class node{
    ll sum;
    int i;
    int j;
public:
    node(ll s,int a,int b)
    {
        this->sum = s;
        this->i = a;
        this->j = b;
    }
    ll getSum() const {return sum;}
    int getI() const { return i;}
    int getJ() const { return j;}
};


class myComp{
public:
    int operator() (const node& n1,const node& n2)
    {
        return n1.getSum() < n2.getSum();
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        
        ll a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        int m = n;
        
        ll b[m];
        for(int i=0;i<m;i++)
            cin>>b[i];
        
        sort(a,a+n);
        sort(b,b+m);

        priority_queue<node,vector<node>, myComp> pq;
        pq.push(node(a[n-1]+b[m-1],n-1,m-1));

        // maintain a map so that you dont push a pair which has already been processed (imp)
        map<pair<int,int>,int> mp;
        mp[{n-1,m-1}]=1;
        int c = 0;
        while(1)
        {
            node nd = pq.top();
            
            cout<<nd.getSum()<<" ";
            c++;
            if(c==k)
                break;
            pq.pop();
            pair<int,int> p1 = {nd.getI(),nd.getJ()-1};
            pair<int,int> p2 = {nd.getI()-1,nd.getJ()};

            // push only if not yet seen 
            if(mp.find(p1)==mp.end())
            {
                node nd1 = node(a[nd.getI()]+b[nd.getJ()-1],nd.getI(),nd.getJ()-1);
                pq.push(nd1);
                mp[p1]=1;
            }
            if(mp.find(p2)==mp.end())
            {
                node nd2 = node(a[nd.getI()-1]+b[nd.getJ()],nd.getI()-1,nd.getJ());
                pq.push(nd2);
                mp[p2]=1;
            }
        }
        cout<<endl;
    }
    

}