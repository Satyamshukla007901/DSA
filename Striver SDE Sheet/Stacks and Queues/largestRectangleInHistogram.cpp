//https://leetcode.com/problems/largest-rectangle-in-histogram/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
       
        stack<int> st;
        int area=0;
        int n = heights.size();
        vector<int> l(n,0);
        vector<int> r(n,0);
        
        for(int i=0;i<n;i++)
        {
            while(!st.empty()&&heights[st.top()]>=heights[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                l[i]=0;
            }
            else
                l[i]=st.top()+1;
            st.push(i);
        }
        
        while(!st.empty())
                st.pop();
        
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty()&&heights[i]<=heights[st.top()])
                    st.pop();
            if(st.empty())
                    r[i]=n-1;
            else
                    r[i]=st.top()-1;
            st.push(i);
        }
        int ans = INT_MIN;
        for(int i=0;i<n;i++)
                ans=max(ans,(r[i]-l[i]+1)*heights[i]);
        return ans;
    }
};


// most optimal solution
// TC-->O(2N)  SC-->O(N)
// while finding the left smaller element at the end of the array we always end up
// having a stack that contains elements in linearly increasing order.
// so for an element if it is smaller than the stacks top ellement then for that stacks top RS = curr eelemnet and LS = 
// the elemnet below curr stacks top
        stack<int> st;
        int ans = 0;
        int n = heights.size();
        for(int i=0;i<=n;i++)
        {
            while(!st.empty() and (i==n || heights[st.top()]>=heights[i]))
            {
                int height = heights[st.top()];
                st.pop();
                int width;
                if(st.empty())
                {
                    width = i;
                }
                else
                {
                    width = i-st.top()-1;
                }
                
                ans = max(ans,height*(width));
            
            }
            st.push(i);
        }
        
        
        return ans;