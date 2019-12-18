import java.util.*;

public class jump_game2{
      public static final int INF = 1000001;
      public static void main(String[] args)
      {
            Scanner scan = new Scanner(System.in);
            int n = scan.nextInt();
            int[] a = new int[n];
            for(int i=0;i<n;i++)
                  a[i] = scan.nextInt();
            int[] dp = new int[n];
            for(int i=1;i<n;i++)
                  dp[i] = INF;
            for(int i=0;i<n;i++)
            {
                  for(int j=i+1;j<=i+a[i];j++)
                  {
                        if(j>=n)
                              break;
                        dp[j] = Math.min(dp[j],dp[i]+1);
                  }
            }
            System.out.println(dp[n-1]);
      }

}
