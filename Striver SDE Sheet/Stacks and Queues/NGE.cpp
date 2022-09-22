//https://leetcode.com/problems/next-greater-element-ii/description/
class Solution {
public:
void nextLargerElement(vector<int> arr, int n,vector<int> &ans,stack<int> &st)
{
   
    ans[n - 1] = -1;
    
    st.push(arr[n - 1]);
    for (int i = n - 2; i >= 0; i--)
    {
        if (!st.empty() && st.top() <= arr[i])
        {
            while (!st.empty() && st.top() <= arr[i])
                st.pop();
            if (st.empty())
                ans[i] = -1;
            else
                ans[i] = st.top();
        }
        else
        {
            ans[i] = st.top();
        }
        st.push(arr[i]);
    }
   
    // Your code here
}
    vector<int> nextGreaterElements(vector<int>& nums) {
        /*
        vector<int> ok(nums.size()*2);
        for(int i=0;i<nums.size();i++)
                ok[i]=nums[i];
        int idx=0;
        for(int i=nums.size();i<2*nums.size();i++)
        {        
            if(idx<nums.size())
                ok[i]=nums[idx++];
        }
        vector<int> ans = nextLargerElement(ok,ok.size());
        vector<int> op;
        for(int i=0;i<nums.size();i++)
                op.push_back(ans[i]);
        return op;*/
        stack<int> st;
        vector<int> ans(nums.size());int n = nums.size();
        nextLargerElement(nums,nums.size(),ans,st);
        for (int i = n - 1; i >= 0; i--)
        {
            if (!st.empty() && st.top() <= nums[i])
            {
                while (!st.empty() && st.top() <= nums[i])
                    st.pop();
                if (st.empty())
                    ans[i] = -1;
                else
                    ans[i] = st.top();
            }
            else
            {
                ans[i] = st.top();
            }
            st.push(nums[i]);
        }
        return ans;
    }
};