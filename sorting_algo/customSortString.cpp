map<char,int> mp;
bool compare(char a,char b)
{
    if(mp.find(a)!=mp.end() and mp.find(b)!=mp.end())
        return mp[a]<mp[b];
    if(mp.find(a)!=mp.end())
        return false;
    if(mp.find(b)!=mp.end())
        return true;
    return a<b;
}
class Solution {
public:
    string customSortString(string S, string T) {
        mp.clear();
        for(int i=0;i<S.length();i++)
            mp[S[i]]=i;
        sort(T.begin(),T.end(),compare);
        return T;
        
    }
};