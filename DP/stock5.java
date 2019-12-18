import java.util.*;

public class stock5{
      public static void main(String[] args)
      {
            Scanner scan = new Scanner(System.in);
            int n = scan.nextInt();
            int[] a = new int[n];
            for(int i=0;i<n;i++)
                  a[i] = scan.nextInt();
            int fee = scan.nextInt();

            // dp state - max profit gained till ith day ( either do transaction(use fees) or not do transaction(dont use fees))
            int[] buy = new int[n+1];
            int[] sell = new int[n+1];
            buy[0] = a[0];
            for(int i=1;i<n;i++)
            {
                  buy[i] = Math.max(buy[i-1],sell[i-1]-a[i] - fee);
                  sell[i] = Math.max(sell[i-1],a[i]+buy[i-1]);
            }
            int ans = sell[n-1];
            System.out.println(ans);
      }
}
