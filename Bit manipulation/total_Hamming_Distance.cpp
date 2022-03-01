//https://leetcode.com/problems/total-hamming-distance/
    int totalHammingDistance(vector<int>& nums) {
        vector<int> ok(32,0);
        for(auto &value:nums)
        {
            for(int i=0;i<32;i++)
            {
                if((value>>i)&1)
                {
                    ok[i]++;
                }
            }
        }
        int cnt = 0;
        for(auto &value:ok)
        {
            cnt+=(value)*(nums.size()-value);
        }
        return cnt;
    }