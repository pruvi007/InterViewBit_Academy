/*
	given array of choclates
	a kid eats all chocolates from a jar, then magician fills it by A/2
	Find the max total amount of choclates he has eaten

	maintain a max heap of elements and pop() then push a/2;
*/
// solution by @pruvi007
#define ll long long int
ll mod = 1e9+7;
int Solution::nchoc(int A, vector<int> &B) {
    priority_queue<ll> pq;
    int n = B.size();

    // create the max heap
    for(int i=0;i<n;i++)
        pq.push(B[i]);
    ll sum = 0;
    for(int i=0;i<A;i++)
    {
    	// get the max chocolates
        int x = pq.top();
        pq.pop();
        sum = (sum%mod + x%mod)%mod;

        // push back a/2 and heapify
        pq.push(x/2);
    }
    return sum%mod;
}

