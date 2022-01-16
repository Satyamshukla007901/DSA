//https://leetcode.com/problems/single-number-iii/submissions/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        /*
        unordered_map<int,int> mp;
        for(auto &value:nums)
                mp[value]++;
        vector<int> ans;
        for(auto &value:mp)
        {
            if(value.second==1)
                    ans.push_back(value.first);
        }
        return ans;*/
        int ok = 0;
        for(auto &value:nums)
                ok=ok^value;
        int a = 0;
        for(int i=0;i<32;i++)
        {
            if((ok>>i)&1)
                    a=i;
        }
        vector<int> op1;
        vector<int> op2;
        for(auto &value:nums)
        {
            if(value&(1<<a))
                op1.push_back(value);
            else
                op2.push_back(value);
        }
        int num1=0,num2=0;
        for(auto &value:op1)
                num1=num1^value;
        for(auto &value:op2)
                num2=num2^value;
        return {num1,num2};
    }
};
//https://leetcode.com/problems/single-number/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        /*
        int ans = nums[0];
        for(int i=1;i<nums.size();i++)
                ans^=nums[i];
        return ans;*/
        unordered_map<int,int> mp;
        for(auto &value:nums)
        {
            mp[value]++;
        }
        for(auto &value:mp)
        {
            if(value.second==1)
                    return value.first;
        }
        return -1;
           
    }
};
//https://leetcode.com/problems/single-number-ii/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        vector<int> vp(32,0);
        for(auto &value:nums)
        {
            for(int i=0;i<32;i++)
            {
                if(((value>>i)&1))
                {
                    vp[i]++;
                }
            }
        }
        // for(auto &value:vp)
        //         cout<<value<<" ";
        // cout<<endl;
        int num = 0;
        for(int i=31;i>=0;i--)
        {
            if(vp[i]%3!=0)
            {
                num=num+(1<<i);
            }
        }
        return num;
    }
};
//https://leetcode.com/problems/xor-queries-of-a-subarray/submissions/
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int N = arr.size();
        vector<int> prefix(N,0);
        prefix[0]=arr[0];
        for(int i=1;i<N;i++)
        {
            prefix[i]=prefix[i-1]^arr[i];
        }
        vector<int> ans;
        for(auto &value:queries)
        {
            if(value[0]==0)
            {
                ans.push_back(prefix[value[1]]);
            }
            else
                ans.push_back(prefix[value[1]]^prefix[value[0]-1]);
        }
        return ans;
    }
};