//https://leetcode.com/problems/coin-change-2/submissions/
class Solution {
public:
    int f(int i,int T,vector<int> &vp,vector<vector<int>> &dp)
    {
        if(i==0)
        {
            if(T%vp[i]==0) return 1;
            return 0;
        }
        if(dp[i][T]!=-1) return dp[i][T];
        int notTake = f(i-1,T,vp,dp);
        int Take = 0;
        if(vp[i]<=T)
        {
            Take = f(i,T-vp[i],vp,dp);
        }
        return dp[i][T]=Take+notTake;
    }
    int change(int amount, vector<int>& coins) {
        
        
        // return f(coins.size()-1,amount,coins);
        //now memoisation
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        // return f(coins.size()-1,amount,coins,dp);
        
        //tabulation
        
        
        
        return dp[coins.size()-1][amount];
        
    }
};