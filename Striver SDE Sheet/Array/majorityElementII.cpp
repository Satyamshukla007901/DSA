//https://leetcode.com/problems/majority-element-ii/submissions/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        /*
        int n = nums.size();
        int ok = n/3;
        unordered_map<int,int> mp;
        for(auto &value:nums)
                mp[value]++;
        vector<int> ans;
        for(auto &value:mp)
        {
            if(value.second>ok)
                    ans.push_back(value.first);
        }
        return ans;*/
        int cnt1 = 0;
        int cnt2 = 0;
        long long ans1 = 1e9+1;
        long long ans2 = 1e9+1;
        for(auto &value:nums)
        {
            if(value==ans1) cnt1++;
            else if(value==ans2) cnt2++;
            else if(cnt1==0)
            {
                ans1 = value;
                cnt1=1;
            }
            else if(cnt2==0)
            {
                ans2=value;
                cnt2=1;
            }
            else
            {
                cnt1--;
                cnt2--;
            }

            
        }
        cout<<ans1<<" "<<ans2<<endl;
        cnt1 = 0;
        cnt2 = 0;
        for(auto &value:nums)
        {
            if(value==ans1) cnt1++;
            else if(value==ans2) cnt2++;
        }
        
        if(cnt1>nums.size()/3 and cnt2>nums.size()/3) return {int(ans1),int(ans2)};
        else if(cnt1>nums.size()/3) return {int(ans1)};
        else if(cnt2>nums.size()/3) return {int(ans2)};
        return {};
        
    }
};