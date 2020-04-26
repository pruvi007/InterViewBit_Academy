#include<bits/stdc++.h>
using namespace std;
bool Comp(pair<int,int> &a,pair<int,int> &b)
{
    // int s1 = a.first + a.second;
    // int s2 = b.first + b.second;
    // return s1<s2;
    return abs(a.first)+abs(a.second) < abs(b.first)+abs(b.second);

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    int x,y;
    int c=0;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++)
    {
        cin >> x >> y;
        c+=2;
        if(x!=0)
            c+=2;
        if(y!=0)
            c+=2;
        v.push_back({x,y});
    }
    sort(v.begin(),v.end(),Comp);

    cout << c << endl;
    for(int i=0;i<n;i++)
    {
        x = v[i].first;
        y = v[i].second;

        if(abs(x)) 
            cout << "1 " << abs(x) << " " << (x>0?'R':'L') << "\n"; 
            // printf("1 %d %c\n", abs(x), x>0?'R':'L');
        if(abs(y)) 
            cout << "1 " << abs(y) << " " << (y>0?'U':'D') << "\n"; 
            // printf("1 %d %c\n", abs(y), y>0?'U':'D');
        cout << 2 << "\n";
        if(abs(x)) 
            cout << "1 "<< abs(x) << " " << (x>0?'L':'R') << "\n";
            // printf("1 %d %c\n", abs(x), x>0?'L':'R');
        if(abs(y)) 
            cout << "1 " << abs(y) << " " << (y>0?'D':'U') << "\n";
            // printf("1 %d %c\n", abs(y), y>0?'D':'U');
        cout << 3 << "\n";



    }

}