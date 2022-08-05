//https://leetcode.com/problems/two-sum/submissions/
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    return {i,j};
                }
            }
        }
        return {-1,-1};*/
        map<int,vector<int>> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]].push_back(i);
        }
        for(int i=0;i<nums.size();i++)
        {
            int k = target-nums[i];
            int hmm = -1;
            
            for(auto &value:mp[k])
            {
                if(value!=i)
                {
                    hmm=value;break;
                }
            }
            if(hmm!=-1) return {i,hmm};
        }
        return {-1,-1};