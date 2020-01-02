#include<bits/stdc++.h>
using namespace std;
int m = 1;

int main()
{
      int n;
      cin >> n;

      // state - dp[i] - it stores ans till i
      int dp[n+1]={0};
      dp[1] = 1;
      dp[2] = 1;
      for(int i=3;i<=n;i++)
      {
            // say we have n = 8, then we will check for 1+7, 2+6, 3+5, 4+4 ,
            // but those numbers can be further broken down, so we also need their dp states (prev)
            // that is , max(4,dp[4]) where dp[4] is answer of 4
            for(int j=1;j<i;j++)
            {
                  dp[i] = max( dp[i], max(j,dp[j])*max(i-j,dp[i-j])  );
            }
      }
      cout << dp[n] << endl;

}
