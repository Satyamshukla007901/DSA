//https://leetcode.com/contest/weekly-contest-318/problems/maximum-sum-of-distinct-subarrays-with-length-k/
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sum = 0;
        map<long long,long long> mp;
        int i = 0;
        long long ans = 0;
        int j = 0;
        int N = nums.size();
        while(j<N)
        {
            sum+=nums[j];
            mp[nums[j]]++;
            if(mp.size()==j-i+1 and mp.size()==k)
            {
                ans = max(ans,sum);
                j++;
            }
            else if(mp.size()<j-i+1)
            {
                while(mp.size()<j-i+1)
                {
                    sum-=nums[i];
                    mp[nums[i]]--;
                    if(mp[nums[i]]==0) mp.erase(nums[i]);
                    i++;
                }
                if(mp.size()==j-i+1 and mp.size()==k)
                {
                    ans = max(ans,sum);
                }
                j++;
            }
            else if(mp.size()>k)
            {
                while(mp.size()>k)
                {
                    sum-=nums[i];
                    mp[nums[i]]--;
                    if(mp[nums[i]]==0) mp.erase(nums[i]);
                    i++;
                }
                if(mp.size()==j-i+1 and mp.size()==k)
                {
                    ans = max(ans,sum);
                }
                j++;
            }
            else j++;
        }
        return ans;
    }
};