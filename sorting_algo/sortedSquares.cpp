// O(nlgn) approach using comparator

bool compare(int a,int b)
{
    return a*a < b*b;
}
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        sort(A.begin(),A.end(),compare);
        for(int i=0;i<A.size();i++)
            A[i] *= A[i];
        return A;
        
    }
};

// O(n) approach
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int l=0,r=0;
        for(int i=0;i<A.size();i++)
        {
            if(A[i]>=0)
            {
                r=i;
                break;
            }
        }
        l=r-1;
        vector<int> ans;
        while(l>=0 and r<A.size())
        {
            if(abs(A[l]) <abs(A[r]) )
            {
                ans.push_back(A[l]*A[l]);
                l--;
            }
            else
            {
                ans.push_back(A[r]*A[r]);
                r++;
            }
        }
        while(l>=0)
        {
            ans.push_back(A[l]*A[l]);
            l--;
        }
        while(r<A.size())
        {
            ans.push_back(A[r]*A[r]);
            r++;
        }
        return ans;
    }
};