//   https://leetcode.com/problems/permutations/
 void solve(vector<int> nums,int idx,vector<vector<int>> &ans)
    {
        /* My approach Space complexity is O(N)+ stack space
        if(nums.size()==0)
        {
            ans.push_back(op);
            return;
        }
        vector<int> temp = nums;
        for(int i=0;i<nums.size();i++)
        {
            vector<int> help = op;
            help.push_back(nums[i]);
            nums.erase(nums.begin()+i);
            solve(nums,help,ans);
            nums=temp;
            
        }*/
        
        if(idx>=nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for(int i=idx;i<nums.size();i++)
        {
            swap(nums[i],nums[idx]);
            solve(nums,idx+1,ans);
            swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> ok;
        solve(nums,0,ans);
        return ans;
        
    }