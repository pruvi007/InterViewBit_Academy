 int mincostTickets(vector<int>& days, vector<int>& costs) {
        int last = days[days.size()-1];
        int dp[last+1];
       
        
        dp[0] = 0; 
        int l=0;
        for(int i=1;i<=last;i++)
        {
            if( i==days[l] )
            {
                if(i>=30)
                    dp[i]=min(dp[i-1]+costs[0],min(dp[i-7]+costs[1],dp[i-30]+costs[2]));
                else if(i>=7)
                    dp[i]=min(dp[i-1]+costs[0],min(dp[i-7]+costs[1],dp[0]+costs[2]));
                else dp[i]=min(dp[i-1]+costs[0],min(dp[0]+costs[1],dp[0]+costs[2]));
                l+=1;
            }else{
                dp[i] = dp[i-1];
            }
        }
        // for(int i=1;i<=last;i++)
        //     cout << dp[i] << " ";
        return dp[last];
        
    }