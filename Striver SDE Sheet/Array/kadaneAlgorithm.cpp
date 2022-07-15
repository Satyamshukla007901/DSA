//https://leetcode.com/problems/maximum-subarray/submissions/
        map<int,int> mp;
        // 1 -> count of positive numbers
        // 2 -> count of negative numbers
        for(auto &value:nums)
        {
            if(value>0) mp[1]++;
            else mp[2]++;
        }
        if(mp[2]==nums.size())
        {
            int maxi = INT_MIN;
            for(auto &value:nums)
            {
                maxi = max(maxi,value);
            }
            return maxi;
        }
        
        int curr = 0;
        int maxi = INT_MIN;
        for(auto &value:nums)
        {
            curr+=value;
            maxi = max(curr,maxi);
            if(curr<0) curr=0;
        }
        return maxi;