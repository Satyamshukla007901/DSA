//https://leetcode.com/problems/3sum/
        int l = nums.size();
        vector<vector<int>> ans;
        if(l<=2) return ans;
        set<vector<int>> s;
        sort(nums.begin(),nums.end());
        for(int i=0;i<l;i++)
        {
            int k = 0-(nums[i]);
            int f = i+1;
            int e = l-1;
            while(f<e)
            {
                int sum = nums[f]+nums[e];
                if(sum<k)
                {
                    f++;
                }
                else if(sum>k)
                {
                    e--;
                }
                else
                {
                    s.insert({nums[i],nums[f],nums[e]});
                    f++;e--;
                }
            }
        }
        for(auto &value:s)
        {
            ans.push_back(value);
        }
        return ans;