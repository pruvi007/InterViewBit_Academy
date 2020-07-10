

/*

Last week Saraswathi celebrated her 3rd birthday. She received a xylophone as a birthday gift. This xylophone has 8 keys(A,B,C,D,E,F,G,H). Saraswathi started liking the tunes she could produce with that. She does not like certain sequences that make her cry. A tune is unpleasant when it contains a sequence that make her cry. All other tunes are pleasant tunes. Ram her brother who is studying combinatorics in school, wants to find out for a given tune how many distinct non-empty sub tunes exist that are pleasant. Can you help Ram by writing a program that answers his question?
T - Given tune
S - sub tune of the given tune
T - any combination of keys (A,B,C,D,E,F,G,H)
S - where every key used is present in T. If a particular key is present in T K times then you can use that key in S upto K times.

Example 1
T - ABC
S - A, B, C, AB, BA, AC, CA, BC, CB, ABC, ACB, BAC, BCA, CBA, CAB.

Example 2
T - AAB
S - A, B, AA, AB, BA, AAB, ABA, BAA

Input Format
Given Tune
N - (number of tunes that saraswathi dislikes)
N-lines each containing one such tune.

Constraints
Length of the Tune is <= 8

Output Format
Number of pleasant subtunes of the given tune.

Sample Input 0
AB
1
AB
Sample Output 0
3

*/
#include<bits/stdc++.h>
using namespace std;
#define ll          long long int
#define fast         ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define INF          1e18
#define Vi           vector<int> 
#define VI           vector<vector<int> >
#define VL           vector<vector<long long int> > 
#define PII          pair<int,int> 
#define PLL          pair<long long int,long long int>
#define PSI          pair<string,int>
#define PB           push_back

int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};
int DX[] = {0,-1,-1,-1,0,1,1,1};
int DY[] = {-1,-1,0,1,1,1,0,-1};
map<string,int> mp,soFar;
int ans = 0;

bool isSub(string a, string b)
{
    // check if b is a subseq of a
    if(b.length() > a.length())
        return false;
    if(b.length()==a.length())
        return a==b;
    int l=0;
    for(int i=0;i<a.length();i++)
    {
        if(a[i]==b[l])
            l+=1;
    }
    return l==b.length();
}
void genPerm(string cur,int l)
{
    if(l>=cur.length())
    {
        
        if(cur.length()>=1 and soFar.find(cur)==soFar.end())
        {
            soFar[cur]=1;
            bool flag = false;
            for(auto it=mp.begin();it!=mp.end();it++)
            {
                string unp = it->first;
                if(isSub(cur,unp))
                {
                    flag=true;
                    break;
                }
            }
            if(flag==false)
            {
                // cout << cur << " ";
                ans += 1;
            }
                
            // cout << cur << ", ";
        }
            
        return;
    }
    for(int i=l;i<cur.length();i++)
    {
        char temp = cur[l];
        cur[l] = cur[i];
        cur[i] = temp;

        genPerm(cur,l+1);

        temp = cur[l];
        cur[l] = cur[i];
        cur[i] = temp;

    }
}
void genComb(string given,int l,string cur)
{
    if(l>=given.length())
    {
        // gen perms
        // cout << cur << ":";
        genPerm(cur,0);
        // cout << endl;
        return;
    }
    cur.PB(given[l]);
    genComb(given,l+1,cur);
    cur.pop_back();
    genComb(given,l+1,cur);
}
int main()
{
    fast;
    string given;
    cin >> given;
    int n;
    cin >> n;
    
    for(int i=0;i<n;i++)
    {
        string x;
        cin >> x;
        mp[x] = 1;
    }
    genComb(given,0,"");
    cout << ans << endl;
}
