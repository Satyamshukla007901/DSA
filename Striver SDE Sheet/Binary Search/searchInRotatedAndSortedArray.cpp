//https://leetcode.com/problems/search-in-rotated-sorted-array/
class Solution {
public:
    int pivot(vector<int> vp,int n)
    {
        int s = 0;
        int e = n-1;
        while(s<=e)
        {
            int mid = s + (e-s)/2;
            if(vp[(mid-1+n)%n]>vp[mid]&&vp[mid]<vp[(mid+1)%n])
                return mid;
            else if(vp[mid]>=vp[0])
                s = mid+1;
            else
                e=mid-1;
        }
        return 0;
    }
               
    int bSearch(vector<int> vp,int start,int end,int target)
    {
             while(start<=end)
             {
                 int mid = start + (end-start)/2;
                 if(vp[mid]==target)
                        return mid;
                 else if(vp[mid]<target)
                        start = mid + 1;
                 else
                        end = mid-1;
             }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int idx = pivot(nums,nums.size());
        if(n==1)
        {
            if(nums[0]==target)
                    return 0;
            return -1;
        }
        

        if(target>=nums[idx]&&target<=nums[n-1])
        {
            return bSearch(nums,idx,n-1,target);
        }
        else
            return bSearch(nums,0,idx-1,target);
        return -1;
        
    }
};