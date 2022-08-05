//https://leetcode.com/problems/combination-sum-ii/submissions/
    void f(int idx,vector<int> &nums,vector<int> ok,int sum,vector<vector<int>> &ans,int target)
    {
        if(idx==nums.size())
        {
            if(sum==target)
            {
                ans.push_back(ok);return;
            }
            return;
        }
        else if(sum>target) return;
        
        ok.push_back(nums[idx]);
        sum+=nums[idx];
        f(idx+1,nums,ok,sum,ans,target);
        sum-=nums[idx];
        ok.pop_back();
        while(idx<nums.size() and idx+1<nums.size() and nums[idx]==nums[idx+1])
            idx++;
        f(idx+1,nums,ok,sum,ans,target);
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
       
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> ok;
        f(0,candidates,ok,0,ans,target);
        
        
        return ans;
    }