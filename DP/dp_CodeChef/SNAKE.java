import java.util.*;


public class SNAKE{
      public static void main(String[] args)
      {
            Scanner scan = new Scanner(System.in);

            int n = scan.nextInt();
            ArrayList< Pair > l1,l2;
            l1 = new ArrayList< Pair >();l2 = new ArrayList< Pair >();
            for(int i=0;i<n;i++)
            {
                  int x,y;
                  x = scan.nextInt();y = scan.nextInt();
                  l1.add( new Pair(x,y) );
            }
            int m = scan.nextInt();
            for(int i=0;i<m;i++)
            {
                  int x,y;
                  x = scan.nextInt();y = scan.nextInt();
                  l2.add( new Pair(x,y) );
            }
            int size = Math.max(n,m);
            int[][] board = new int[size+1][size+1];
            for(Pair x:l1)
            {
                  int i = x.first,j = x.second;
                  board[i][j] += 1;
            }
            for(Pair x:l2)
            {
                  int i = x.first,j = x.second;
                  board[i][j] += 1;
            }
            for(int i=0;i<=size;i++)
            {
                  for(int j=1;j<=size;j++)
                        System.out.print(board[i][j]);
                  System.out.println();
            }
      }

}
