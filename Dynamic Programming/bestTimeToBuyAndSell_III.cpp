//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/submissions/
class Solution {
public:
    int f(int i,int b,int c,int N,vector<int> &prices,vector<vector<vector<int>>> &dp)
    {
        if(c==0) return 0;
        if(i==N) return 0;
        
        
        if(dp[i][b][c]!=-1) return dp[i][b][c];
        if(b==1)
        {
            return dp[i][b][c] = max(-prices[i]+f(i+1,0,c,N,prices,dp),f(i+1,1,c,N,prices,dp));
        }
        return dp[i][b][c] = max(prices[i]+f(i+1,1,c-1,N,prices,dp),f(i+1,0,c,N,prices,dp));
    }
    int maxProfit(vector<int>& prices) {
        int N = prices.size();
        // return f(0,1,2,N,prices);
        //memoisation
        // vector<vector<vector<int>>> dp(N,vector<vector<int>>(2,vector<int>(3,-1)));
        // return f(0,1,2,N,prices,dp);
        //tabulation
        vector<vector<vector<int>>> dp(N+1,vector<vector<int>>(2,vector<int>(3,0)));
        
        for(int i=N-1;i>=0;i--)
        {
            for(int b = 0;b<=1;b++)
            {
                for(int c = 1;c<=2;c++)
                {
                    if(b==1)
                    {
                        dp[i][b][c] = max(-prices[i]+dp[i+1][0][c],dp[i+1][1][c]);
                    }
                    else
                    {
                        dp[i][b][c] = max(prices[i]+dp[i+1][1][c-1],dp[i+1][0][c]);
                    }
                }
            }
        }
        return dp[0][1][2];

    }
};