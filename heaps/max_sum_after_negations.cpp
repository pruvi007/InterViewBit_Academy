/*
    find the max sum of given  array after k negations.
    idea: use min heap and always negate the top element.
*/
// solution by @pruvi007

#define ll long long int
int Solution::solve(vector<int> &A, int B) {
    priority_queue<ll,vector<ll>,greater<ll> > pq;
    for(int i=0;i<A.size();i++)
        pq.push(A[i]);
    for(int i=B-1;i>=0;i--)
    {
        ll x = pq.top();
        if(x>=0)
        {
            if(i%2==0)
            {
                pq.pop();
                pq.push(-x);
                break;
            }
            else
            {
                pq.pop();
                pq.push(x);
                break;
            }
        }
        pq.pop();
        pq.push(-x);
    }
    ll sum = 0;
    while(!pq.empty())
    {
        sum+=pq.top();
        pq.pop();
    }
    return sum;
}
