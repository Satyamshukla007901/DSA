//https://leetcode.com/problems/remove-duplicates-from-sorted-array/submissions/
        //TC-O(N)
        //SC-O(1)
        int i = 0;
        int j=0;
        vector<int> ans;
        while(i<nums.size())
        {
            while(i+1<nums.size() and nums[i]==nums[i+1])
            {
                i++;
            }
            nums[j++]=nums[i];
            i++;
        }
        
        return j;