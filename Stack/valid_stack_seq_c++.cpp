//https://leetcode.com/problems/validate-stack-sequences/
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        int i=0;int j=0;stack<int> st;
        while(i<pushed.size()&&j<popped.size())
        {
            if(st.empty())
            {
                st.push(pushed[i]);
                i++;
            }
            else if(st.top()!=popped[j])
            {
                st.push(pushed[i]);
                i++;
            }
            if(st.top()==popped[j])
            {
                st.pop();
                j++;
            }
        }
        while(!st.empty()&&j<popped.size())
        {
            if(st.top()==popped[j])
            {
                st.pop();
                
            }
            j++;
        }
        if(i==pushed.size()&&j==popped.size()&&st.empty())
                return true;
        return false;
    }
};