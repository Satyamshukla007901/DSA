//https://leetcode.com/problems/sliding-window-maximum/submissions/
// TC--> O(NlogN)
// SC-->O(K)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        priority_queue<pair<int,int>> pq;
        vector<int> ans;
        while(j<nums.size())
        {
            pq.push({nums[j],j});
            if(j-i+1<k)
            {
                j++;
            }
            else if(j-i+1==k)
            {
                while(pq.top().second<i)
                    pq.pop();
                ans.push_back(pq.top().first);
                j++;
            }
            else
            {
                while(j-i+1>k)
                {
                    if(pq.top().second==i) pq.pop();
                    i++;
                    
                }
                if(j-i+1==k)
                {
                    while(pq.top().second<i)
                        pq.pop();
                    ans.push_back(pq.rop());
                }
                j++;
            }
        }
        return ans;
    }
};

//  TC-->O(N)

//  SC-->O(K)
#include <list>
vector<int> Solution::slidingMaximum(const vector<int> &A, int B)
{
    if (B > A.size())
    {
        vector<int> ok;
        ok.push_back(*max_element(A.begin(), A.end()));
        return ok;
    }
    int i = 0;
    int j = 0;
    int N = A.size();
    vector<int> ok;
    dequeue<int> st;

    while (j < N)
    {
        //Calculation
        while (st.size() > 0 && st.back() < A[j])
            st.pop_back();
        st.push_back(A[j]);
        if (j - i + 1 < B)
        {

            j++;
        }
        else if (j - i + 1 == B)
        {
            ok.push_back(st.front());
            if (A[i] == st.front())
                st.pop_front();
            j++;
            i++;
        }
    }
    return ok;
}