//https://leetcode.com/problems/combination-sum/
    void f(int idx,vector<int> &arr,int target,vector<int> &ok,vector<vector<int>> &ans,int sum)
    {
        if(idx==arr.size())
        {
            if(target==sum)
            {
                ans.push_back(ok);
                return;
            }
            return;
        }
        else if(sum>target)
        {
            return;
        }
        
        ok.push_back(arr[idx]);
        sum+=arr[idx];
        f(idx,arr,target,ok,ans,sum);
        ok.pop_back();
        sum-=arr[idx];
        f(idx+1,arr,target,ok,ans,sum);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        
        vector<int> ok;
        vector<vector<int>> ans;
        f(0,candidates,target,ok,ans,0);
        
        
        return ans;
        
        
    }