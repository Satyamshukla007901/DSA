//https://leetcode.com/problems/combination-sum/submissions/
    void solve(vector<int> candidates,int target,vector<vector<int>> &ans,vector<int> ok)
    {
        if(candidates.size()==0)
        {
            if(target==0)
            {
                ans.push_back(ok);
                return;
            }
            return;
        }
        else if(target==0)
        {
            ans.push_back(ok);
            return;
        }
        else if(target<0)
        {
            return;
        }


        int x = target/candidates[0];
        int item = candidates[0];
        candidates.erase(candidates.begin());
        for(int i=0;i<=x;i++)
        {
            int rem = target - item*i;
            vector<int> hmm=ok;
            for(int j=1;j<=i;j++)
            {
                hmm.push_back(item);
            }
            solve(candidates,rem,ans,hmm);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ok;
        solve(candidates,target,ans,ok);
        return ans;
    }