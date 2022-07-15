//https://leetcode.com/problems/subarray-product-less-than-k/
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0;
        int N = nums.size();
        int tot  = (N*(N+1))/2;
        int cnt = 0;
        long long pro;
        int i=0;
        int j = 0;
        pro = 1;
        while(j<N)
        {
            pro*=nums[j];
            if(pro<k)
            {
                cnt+=j-i+1;
                j++;
            }
            else
            {
                while(pro>=k)
                {
                    
                    pro/=nums[i];
                    i++; 
                }
                cnt+=j-i+1;
                j++;
            }
            
        }
        return cnt;
    }
};