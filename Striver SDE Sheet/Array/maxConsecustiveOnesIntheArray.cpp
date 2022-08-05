//https://leetcode.com/problems/max-consecutive-ones
        int ans = 0;
        int cnt = 0;
        for(auto &value:nums)
        {
            if(value==1)
            {
                cnt++;
            }
            else
            {
                ans = max(ans,cnt);
                cnt=0;
            }
        }
        if(cnt) ans = max(ans,cnt);
        return ans;