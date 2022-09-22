//https://leetcode.com/problems/single-element-in-a-sorted-array/
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        /*
        TC --> O(N)
        int ok = nums[0];
        for(int i=1;i<nums.size();i++) ok=ok^nums[i];
        return ok;*/
        
        int s = 0;
        int e = nums.size()-1;
        if(nums.size()==1)
                return nums[0];
        while(s<=e)
        {
            int mid = s + (e-s)/2;
            if(mid-1>=0&&mid+1<nums.size()&&nums[mid-1]!=nums[mid]&&nums[mid+1]!=nums[mid])
            {
                return nums[mid];
            }
            else if(mid+1<nums.size()&&mid==0&&nums[mid]!=nums[mid+1])
            {
                return nums[mid];
            }
            else if(mid-1>=0&&mid==nums.size()-1&&nums[mid-1]!=nums[mid])
            {
                return nums[mid];
            }
            //Cacth of the Problem :-  first occurence of every duyplicate is at even index before single occurence element and first occurence of every duplicate is at odd index after single occurence elemnt
            else if(mid-1>=0&&nums[mid-1]==nums[mid])
            {
                if((mid-1)%2==0)
                {
                    s = mid+1;
                }
                else
                    e = mid-1;
            }
            else
            {
                if((mid+1)%2==0)
                {
                    e = mid-1;
                }
                else
                    s = mid+1;
            }
        }
        return 0; 
    }
};