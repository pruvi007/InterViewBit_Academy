import java.util.*;

public class stock3{
      public static void main(String[] args)
      {
            Scanner scan = new Scanner(System.in);
            int n = scan.nextInt();
            int[] a = new int[n];
            for(int i=0;i<n;i++)
                  a[i] = scan.nextInt();
            int k = scan.nextInt();
            // dp state - max profit by doing k transactions on ith day
            int[][] dp = new int[k+1][n+1];

            // method 1
            for(int tr=1;tr<=k;tr++)
            {
                  for(int i=1;i<n;i++)
                  {
                        int m = a[0];
                        for(int j=1;j<=i;j++)
                        {
                              // if we want tr transactions on j day, then we need to compare it with tr-1 transactions on j-1 th day.
                              m = Math.min( m,a[j]-dp[tr-1][j-1] );
                        }
                        // tr transactions on ith day = max of tr transactions on i-1 th day or what we found out
                        dp[tr][i] = Math.max( dp[tr][i-1],a[i]-m );
                  }
            }
            int ans = dp[k][n-1];
            System.out.println(ans);

            // method 2 - Eliminate calculating Min in each loop
            dp = new int[k+1][n+1];
            for(int tr=1;tr<=k;tr++)
            {
                  int m = a[0];
                  for(int i=1;i<n;i++)
                  {
                        m = Math.min( m,a[i]-dp[tr-1][i-1] );
                        dp[tr][i] = Math.max( dp[tr][i-1],a[i]-m );
                  }
            }
            ans = dp[k][n-1];
            System.out.println(ans);

      }
}
