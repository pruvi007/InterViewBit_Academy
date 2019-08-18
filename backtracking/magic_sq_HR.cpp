/*
	given a 3X3 matrix. Convert it to a magic square with min cost
	idea: gen all magic squares and then find the min cost
	(to generate all permuatation use next_permutation)
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;

// check if gen matrix is magical or not.
bool magic(vector<int> &v)
{
    int a[3][3];
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            a[i][j] = v[3*i + j];
    // sum of magic sq of 3X3 matrix
    int sum = 15;
    // check row sums
    for(int i=0;i<3;i++)
    {
        int s = 0;
        for(int j=0;j<3;j++)
            s += a[i][j];
        if(s != sum)
            return false;
    }
    // check columns
    for(int i=0;i<3;i++)
    {
        int s = 0;
        for(int j=0;j<3;j++)
            s += a[j][i];
        if(s != sum)
            return false;
    }
    // check diagnols
    int s = a[0][0] + a[1][1] + a[2][2];
    if(s != sum)
        return false;
    s = a[0][2] + a[1][1] + a[2][0];
    if(s != sum)
        return false;

    // if nothing has been returned then its a magic sq
    return true;
}
int main()
{
    int mat[3][3];
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            cin >> mat[i][j];
    vector<int> v2;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            v2.push_back(mat[i][j]);

    vector<int> v{1,2,3,4,5,6,7,8,9};
    vector< vector<int> > ms;
    do{
        if(magic(v))
        {
            ms.push_back(v);
        }
    }while( next_permutation(v.begin(),v.end()) );

    int ans = INT_MAX;
    for(int i=0;i<ms.size();i++)
    {
        int d = 0;
        for(int j=0;j<ms[i].size();j++)
        {
  
            d += abs(v2[j] - ms[i][j]);
  
        }
        ans = min(ans,d);
    }
    cout << ans << endl;

}