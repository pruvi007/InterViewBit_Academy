
// O(nlgn) solution usin comparators

map<char,int> mp;
bool compare(char a,char b)
{
    return mp[a]>mp[b] or (mp[a]==mp[b] and a>b);
}

class Solution {
public:
    string frequencySort(string s) {
        mp.clear();
        for(int i=0;i<s.length();i++)
            mp[s[i]]++;
        sort(s.begin(),s.end(),compare);
        return s;
        
    }
};