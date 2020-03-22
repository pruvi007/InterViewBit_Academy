#include<bits/stdc++.h>
using namespace std;
map<int,string> m;
vector<string> ans;
void letter(string s,int level,string temp)
{
  
    if(level==s.length())
    {
        ans.push_back(temp);
        cout << temp << endl;
        return ;
    }
    
    int x = s[level]-'0';
    string w = m[x];
    for(int j=0;j<w.length();j++)
    {
        temp += w[j];
        letter(s,level+1,temp);
        temp.pop_back();
    }
    
}
int main()
{
    string s;
    cin >> s;

    m[0]="0";
    m[1]="1";
    m[2]="abc";
    m[3]="def";
    m[4]="ghi";
    m[5]="jkl";
    m[6]="mno";
    m[7]="pqrs";
    m[8]="tuv";
    m[9]="wxyz";

    letter(s,0,"");



}