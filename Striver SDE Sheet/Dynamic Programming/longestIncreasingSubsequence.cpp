//https://takeuforward.org/interviews/strivers-sde-sheet-top-coding-interview-problems/
class Solution {
public:
    int f(int i,int p,vector<int> &nums,vector<vector<int>> &dp)
    {
        if(i==nums.size()) return 0;
        if(dp[i][p+1]!=-1) return dp[i][p+1];
        int len = 0+f(i+1,p,nums,dp);
        if(p==-1 or nums[i]>nums[p])
        {
            len = max(len,1+f(i+1,i, nums,dp));
        }
        return dp[i][p+1] = len;
    }
    int lengthOfLIS(vector<int>& nums) {
        // vector<vector<int>> dp(nums.size(),vector<int>(nums.size()+1,-1));
        // return f(0,-1,nums,dp);
        //tabulation
        vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,0));
        for(int i=nums.size()-1;i>=0;i--)
        {
            for(int p=i-1;p>=-1;p--)
            {
                int len = 0+dp[i+1][p+1];
                if(p==-1 or nums[i]>nums[p])
                {
                    len = max(len,1+dp[i+1][i+1]);
                }
                dp[i][p+1] = len;
            }
        }
        return dp[0][0];
    }
};



// Recursion TC->2^N SC->N
// Memoisation TC->N*N SC->N*N+N
// Tabulation TC->N*N SC->N*N
// space optimisation TC->N*N SC->N