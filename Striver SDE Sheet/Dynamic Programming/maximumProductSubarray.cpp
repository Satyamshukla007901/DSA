//https://leetcode.com/problems/maximum-product-subarray/
        // TC-->O(N^3)
        // SC-->O(1) 
        int N = nums.size();
        long long ans = INT_MIN;
        for(int i=0;i<N;i++)
        {
            for(int j=i;j<N;j++)
            {
                long long pro = 1;
                for(int k=i;k<=j;k++)
                {
                    pro = pro*nums[k];
                }
                ans = max(ans,pro);
            }
        }
        return ans;



            // TC-->O(N^2)
        // SC-->O(1)
        int N = nums.size();
        long long ans = INT_MIN;
        for(int i=0;i<N;i++)
        {
            long long pro = 1;
            for(int j=i;j<N;j++)
            {
                pro = nums[j]*pro;
                ans = max(ans,pro);
            }
            ans = max(ans,pro);
        }
        return ans;

        // TC --> O(N)
        // SC --> O(1)
        int N = nums.size();
        long long ans = nums[0];
        long long mini = nums[0];
        long long maxi = nums[0];
        for(int i=1;i<N;i++)
        {
            if(nums[i]<0)
            {
                swap(mini,maxi);
            }

            mini = min(mini*nums[i],nums[i]*1LL);
            maxi = max(maxi*nums[i],nums[i]*1LL);
            ans = max(ans,maxi);
        }
        return ans;