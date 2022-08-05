//https://leetcode.com/problems/subsets-ii/
class Solution {
public:
    void f(int idx,int N,vector<int> &arr,vector<int> ok,set<vector<int>> &ans)
    {
        if(idx==N)
        {
            
            ans.insert(ok);
            return;
        }
        
        ok.push_back(arr[idx]);
        f(idx+1,N,arr,ok,ans);
        ok.pop_back();
        f(idx+1,N,arr,ok,ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        /*
        vector<vector<int>> ans;
        int N = nums.size();
        
        for(int i=0;i<pow(2,N);i++)
        {
            vector<int> ok;
            for(int j=0;j<N;j++)
            {
                if((i>>j)&1)
                {
                    ok.push_back(nums[j]);
                }
            }
            ans.push_back(ok);
        }      
        set<vector<int>> s;
        for(auto &value:ans)
        {
            sort(value.begin(),value.end());
            s.insert(value);
        }
        ans.clear();
        for(auto &value:s)
                ans.push_back(value);
        return ans;*/
        
        vector<vector<int>> ans;
        vector<int> ok;
        set<vector<int>> s;
        f(0,nums.size(),nums,ok,s);
        for(auto &value:s) ans.push_back(value);
        
        return ans;
    }
};