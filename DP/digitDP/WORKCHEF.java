import java.util.*;
import java.io.*;


public class sumOfDigits_digitDP {
	public static long[][][][] dp;
	public static final int LCM = 2520;
	public static ArrayList<Integer> digit(long n)
	{
		ArrayList<Integer> ret = new ArrayList<Integer>();
		while(n>0)
		{
			int rem = (int)(n%10);
			ret.add(rem);
			n/=10;
		}
		Collections.reverse(ret);
		return ret;
	}
	public static long solve(ArrayList<Integer> digit,long K,int rem,int sum,int tight,int mask)
	{
		if(rem==digit.size())
		{
			int c = 0;
			for(int i=1;i<=9;i++)
			{
				// if the mask contains the digit i
				if( (mask & (1<<i)) >0 )
				{
					if( sum%i==0 )
						c++;
				}
			}
			if(c>=K)
				return 1;
			return 0;
		}
		if( dp[rem][sum][tight][mask]!=-1)
			return dp[rem][sum][tight][mask];
		
		int upper = (tight==1)?digit.get(rem):9;
		long ans = 0;
		for(int i=0;i<=upper;i++)
		{
			int curTight = (digit.get(rem)==i)?tight:0;
			int newSum = (sum*10 + i)%LCM;
			int newMask = mask | 1<<i;
			ans += solve(digit,K,rem+1,newSum,curTight,newMask);
		}
		dp[rem][sum][tight][mask] = ans;
		return ans;
		
		
	}
	public static long digitDp(ArrayList<Integer> digit,long K)
	{
		// ( noOfDigits,MaxSum,tight,Mask )
		dp = new long[20][2520][2][(1<<9)+5];
		for(int i=0;i<20;i++)
	        for(int j=0;j<200;j++)
	            for(int k=0;k<2;k++)
	                for(int lr=0;lr<517;lr++)
	                    dp[i][j][k][lr]=-1;
		return solve(digit,K,0,0,1,0);
		
	}
	public static void main(String[] args)
	{
		
		Scanner scan = new Scanner(System.in);
		int t = scan.nextInt();
		while(t>0)
		{
			long A,B,K;
			A = scan.nextLong();B=scan.nextLong();K=scan.nextLong();
			ArrayList<Integer> d1,d2;
			d1 = digit(A-1); d2 = digit(B);
			long s1 = digitDp(d1,K);
			long s2 = digitDp(d2,K);
			System.out.println(s2-s1);
			t-=1;
		}
		scan.close();
		
		
	}

}
