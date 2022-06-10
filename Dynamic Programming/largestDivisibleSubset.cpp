//https://leetcode.com/problems/largest-divisible-subset/
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1),hash(n);
        int maxe = 1;
        int l = 0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            hash[i]=i;
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0 and dp[j]+1>dp[i])
                {
                    dp[i] = dp[j]+1;
                    hash[i] = j;
                }
            }
            if(dp[i]>maxe)
            {
                maxe = dp[i];
                l = i;
            }
        }
        // cout<<l<<endl;
        vector<int> ans(maxe);
        int a = maxe-1;
        ans[a] = nums[l];
        a--;
        while(hash[l]!=l)
        {
            l = hash[l];
            ans[a--] = nums[l];
        }
        return ans;
    }
};