class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<int> invalid;
        int n = s.length();
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            if( s[i]=='(' )
                st.push(i);
            else if( s[i]==')')
            {
                if(st.empty())
                    invalid.push_back(i);
                else
                    st.pop();
            }
        }
        while(!st.empty())
        {
            invalid.push_back(st.top());
            st.pop();
        }
        sort(invalid.begin(),invalid.end());
        string ans = "";
        for(int i=0;i<n;i++)
        {
            auto it = lower_bound( invalid.begin(),invalid.end(),i );
            if( it==invalid.end() )
                ans += s[i];
            else
            {
                int p = it-invalid.begin();
                if( invalid[p]!=i )
                    ans+=s[i];
            }
        }
        return ans;
    }
};