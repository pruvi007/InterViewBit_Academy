import java.io.*;
class TestClass{
	
	public static long count(String a, String b) 
	{ 
		long mod = 1000000007;
	    int m = a.length(); 
	    int n = b.length(); 
	    long lookup[][] = new long[m+1][n+1];
	    for (int i = 0; i <= n; ++i) 
	        lookup[0][i] = 0; 

	    for (int i = 0; i <= m; ++i) 
	        lookup[i][0] = 1; 
	 
	    for (int i = 1; i <= m; i++) 
	    { 
	        for (int j = 1; j <= n; j++) 
	        { 
	            if (a.charAt(i - 1) == b.charAt(j - 1)) 
	                lookup[i][j] = lookup[i - 1][j - 1] +  lookup[i - 1][j]; 
	                  
	            else
	                lookup[i][j] = lookup[i - 1][j]; 
	           	lookup[i][j] %= mod;
	        } 
	    } 
	  
	    return lookup[m][n]%mod; 
	} 
	public static void main(String[] args) throws IOException
	{
		BufferedReader scan = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(scan.readLine());
		while(t-- > 0)
		{
			int n = Integer.parseInt(scan.readLine());
			String s = scan.readLine();
			String b = "abcdefghijklmnopqrstuvwxyz";
			long ans = count(s,b);
			System.out.println(ans);
		}
	}
}