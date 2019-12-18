class Solution {
public:
    bool canJump(vector<int>& a) {

        int n = a.size();
        if(n==0)
            return 0;
      // keep track of max possible index to jump to...
      // if i is greater than max then not possible else update max to curIndex+curJump
        int l = 0;
        for(int i=0;i<n;i++)
        {
            if(i>l)
                return false;
            l = (i+a[i])>l?i+a[i]:l;
        }
        return true;
    }
};
