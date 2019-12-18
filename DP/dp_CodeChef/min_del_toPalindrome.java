import java.util.*;

public class min_del_toPalindrome{
      public static void main(String[] args)
      {
            Scanner scan = new Scanner(System.in);
            int t = scan.nextInt();
            for(int z=1;z<=t;z++)
            {
                  String s = scan.next();
                  int n = s.length();
                  int[][] dp = new int[n][n];
                  for(int i=0;i<n;i++)
                        dp[i][i] = 1;
                  for(int len=2;len<=n;len++)
                  {
                        for(int i=0;i<n-len+1;i++)
                        {
                              int j = i+len-1;
                              if( s.charAt(i)==s.charAt(j) && len==2)
                                    dp[i][j] = 2;
                              else if( s.charAt(i)==s.charAt(j) )
                                    dp[i][j] = dp[i+1][j-1] + 2;
                              else
                                    dp[i][j] = Math.max(dp[i][j-1],dp[i+1][j]);

                        }
                  }
                  int pal_seq = dp[0][n-1];
                  System.out.println("Case "+z+": "+(n-pal_seq));

            }
      }
}
