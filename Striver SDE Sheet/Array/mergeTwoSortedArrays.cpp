//https://leetcode.com/problems/merge-sorted-array/submissions/
        if(m==n and n==0) return;
        else if(n==0)
        {
            return;
        }
         int i = m-1;
        int j = n-1;
        int x = n+m-1;
        while(i>=0 and j>=0)
        {
            if(nums1[i]>nums2[j])
            {
                nums1[x] = nums1[i];
                x--;
                i--;
            }
            else
            {
                nums1[x] = nums2[j];
                j--;
                x--;
            }
        }
        while(i>=0)
        {
            nums1[x--] = nums1[i--];
        }
        while(j>=0)
        {
            nums1[x--] = nums2[j--];
        }