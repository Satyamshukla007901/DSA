//https://leetcode.com/problems/next-permutation/
        int i = nums.size()-1;
        while(i>0 and nums[i]<=nums[i-1])
        {
            i--;
        }
        
        int a = i-1;
        if(a>=0)
        {
            int j=nums.size()-1;
            while(j>=0 and nums[a]>=nums[j])
            {
                j--;
            }
            if(j>=0)
            {
                swap(nums[j],nums[a]);
            }
        }
        reverse(nums.begin()+i,nums.end());