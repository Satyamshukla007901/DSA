//https://leetcode.com/problems/4sum/submissions/
        int N = nums.size();
        set<vector<int>> s;
        sort(nums.begin(),nums.end());
        for(int i=0;i<N;i++)
        {
            for(int j=i+1;j<N;j++)
            {
                long long temp = target-1LL*nums[i]-1LL*nums[j];
                int a = j+1;
                int b = N-1;
                while(a<b)
                {
                    int sum = nums[a]+nums[b];
                    if(sum==temp)
                    {
                        vector<int> ok = {nums[i],nums[j],nums[a],nums[b]};
                        sort(ok.begin(),ok.end());
                        s.insert(ok);
                        a++;
                        b--;
                    }
                    else if(sum>temp)
                        b--;
                    else
                        a++;
                }
            }
        }
        for(auto &value:s) ans.push_back(value);
        return ans;