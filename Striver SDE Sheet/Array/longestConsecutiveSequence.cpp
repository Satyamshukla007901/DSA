//https://leetcode.com/problems/longest-consecutive-sequence/
TC - O(N)
SC - O(N)
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
      
        set<int> s;
        for(auto &value:nums)
                s.insert(value);
        nums.clear();
        for(auto &value:s)
                nums.push_back(value);
        int ans = 0;int cnt = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(i+1<nums.size())
            {
                if(nums[i+1]==nums[i]+1)
                {
                    cnt++;
                }
                else
                {
                    ans=max(ans,cnt+1);
                    cnt=0;
                }
                
            }
        }
        ans=max(ans,cnt+1);
        return ans;
    }