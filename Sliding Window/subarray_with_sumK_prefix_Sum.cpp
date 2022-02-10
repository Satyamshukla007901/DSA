//https://leetcode.com/problems/subarray-sum-equals-k/submissions/
int subarraySum(vector<int> &nums, int k)
{

    int i = 0;
    int j = 0;
    int sum = 0;
    int cnt = 0;
    unordered_map<int, int> mp;
    for (i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        if (sum == k)
        {
            cnt++;
        }
        if (mp.find(sum - k) != mp.end())
        {
            cnt += mp[sum - k];
        }
        mp[sum]++;
    }
    return cnt;
}