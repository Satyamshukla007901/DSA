//https://leetcode.com/problems/majority-element/

//approach 1
        unordered_map<int,int> mp;
        for(auto &value:nums)
                mp[value]++;
        for(auto &value:mp)
        {
            if(value.second>nums.size()/2)
                    return value.first;
        }
        return -1;

//appraoch 2
        sort(nums.begin(),nums.end());
        return nums[nums.size()/2];