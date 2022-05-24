//https://leetcode.com/problems/coin-change/submissions/
class Solution {
public:
    int f(int i,int T,vector<int> &a,vector<vector<int>> &dp)
    {
        if(i==0)
        {
            if(T%a[0]==0)
            {
                return T/a[0];
            }
            else
            {
                return 1e9;
            }
        }
        if(dp[i][T]!=-1) return dp[i][T];
        
        int notPick = f(i-1,T,a,dp);int Pick = INT_MAX;
        if(a[i]<=T)
        {
            Pick = 1+f(i,T-a[i],a,dp);
        }
        return dp[i][T] = min(notPick,Pick);
    }
    int coinChange(vector<int>& coins, int amount) {
        // int ok = f(coins.size()-1,amount,coins);
//         now memoisation
        // vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        /*
        int ok = f(coins.size()-1,amount,coins,dp);
        
        if(ok>=1e9)
                return -1;
        return ok;*/
//         now tabulation
        /*
        for(int i=0;i<=amount;i++)
        {
            if(i%coins[0] == 0) dp[0][i] = i/coins[0];
            else dp[0][i] = 1e9;
        }
        
        for(int i=1;i<coins.size();i++)
        {
            for(int j=0;j<=amount;j++)
            {
                int notTake = dp[i-1][j];
                int Take = INT_MAX;
                if(coins[i]<=j) Take = 1+dp[i][j-coins[i]];
                dp[i][j] = min(Take,notTake);
            }
        }
        if(dp[coins.size()-1][amount]>=1e9) return -1;
        return dp[coins.size()-1][amount];*/
        // now space optimisation
        vector<int> prev(amount+1,0),curr(amount+1,0);
        
        for(int i=0;i<=amount;i++)
        {
            if(i%coins[0] == 0) prev[i] = i/coins[0];
            else prev[i] = 1e9;
        }
        
        for(int i=1;i<coins.size();i++)
        {
            for(int j=0;j<=amount;j++)
            {
                int notTake = prev[j];
                int Take = INT_MAX;
                if(coins[i]<=j) Take = 1+curr[j-coins[i]];
                curr[j] = min(Take,notTake);
            }
            prev = curr;
        }
        if(prev[amount]>=1e9) return -1;
        return prev[amount];
        
    }
};