//https://leetcode.com/problems/number-of-longest-increasing-subsequence/submissions/
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();int maxi = 1;
        vector<int> dp(n,1),c(n,1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i] and dp[j]+1>dp[i])
                {
                    dp[i] = dp[j]+1;c[i] = c[j];
                }
                else if(nums[j]<nums[i] and dp[j]+1 == dp[i])
                {
                    c[i]+=c[j];
                }
            }
            maxi = max(maxi,dp[i]);
        }
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            if(dp[i]==maxi)
            {
                ans+=c[i];
            }
        }
        return ans;
    }
};