bool compare(int a,int b)
{
    string sa = to_string(a)+to_string(b);
    string sb = to_string(b)+to_string(a);
    
    return sa>sb;
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        sort(nums.begin(),nums.end(),compare);
        string ans = "";
        for(int i=0;i<nums.size();i++)
            ans += to_string(nums[i]);
        if(ans[0]=='0')
            return "0";
        return ans;
    }
};