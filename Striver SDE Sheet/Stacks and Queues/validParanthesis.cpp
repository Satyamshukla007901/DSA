//https://leetcode.com/problems/valid-parentheses/
/*  TC--> O(N) SC--> O(N)   */
class Solution {
public:
    bool isValid(string s) {
        
        int l = s.length();
        stack<char> st;
        for(int i=0;i<l;i++)
        {
            if(s[i]=='('||s[i]=='{'||s[i]=='[')
                st.push(s[i]);
            else if(s[i]==')')
            {
                if(st.empty()!=true)
                {
                    char ch = st.top();
                    st.pop();
                    if(ch=='(')
                    {
                        
                    }
                    else
                        return false;
                }
                else
                    return false;
            }
            else if(s[i]==']')
            {
                if(st.empty()!=true)
                {
                    char ch = st.top();
                    st.pop();
                    if(ch=='[')
                    {
                        
                    }
                    else
                        return false;
                }
                else
                    return false;
            }
            else if(s[i]=='}')
            {
                if(st.empty()!=true)
                {
                    char ch = st.top();
                    st.pop();
                    if(ch=='{')
                    {
                        
                    }
                    else
                        return false;
                }
                else
                    return false;
            }
        }
        if(st.empty()==false)
            return false;
        return true;
    }
};