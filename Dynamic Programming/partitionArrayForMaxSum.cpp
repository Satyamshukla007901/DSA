//https://leetcode.com/problems/partition-array-for-maximum-sum/submissions/
class Solution {
public:
    int f(int i,vector<int> &arr,int k,vector<int> &dp)
    {
        if(i==arr.size()) return 0;
        
        if(dp[i]!=-1) return dp[i];
        int maxe = INT_MIN;int sum = INT_MIN;
        for(int j=i;j<i+k and j<arr.size();j++)
        {
            maxe = max(arr[j],maxe);
            sum=max(sum,(j-i+1)*maxe+f(j+1,arr,k,dp));
        }
        return dp[i] = sum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        // return f(0,arr,k);
        // vector<int> dp(arr.size(),-1);
        // return f(0,arr,k,dp);
        
        //tabulation
        vector<int> dp(arr.size()+1,0);
        
        for(int i=arr.size()-1;i>=0;i--)
        {
            
            int maxe = INT_MIN;int sum = INT_MIN;
            for(int j=i;j<i+k and j<arr.size();j++)
            {
                maxe = max(arr[j],maxe);
                sum=max(sum,(j-i+1)*maxe+f(j+1,arr,k,dp));
            }
            dp[i] = sum;
        }
        
        return dp[0];
    }
};