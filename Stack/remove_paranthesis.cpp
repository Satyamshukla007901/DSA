//https://leetcode.com/problems/remove-outermost-parentheses/submissions/
    string removeOuterParentheses(string s) {
        string ans="";
        stack<char> st;string temp="";
        for(int i=0;i<s.length();i++)
        {
            ans+=s[i];
            if(st.empty())
            {
                st.push(s[i]);
            }
            else if(s[i]=='(')
            {
                st.push(s[i]);
            }
            else if(s[i]==')'&&st.top()=='(')
            {
                st.pop();
            }
            if(st.empty())
            {
                temp+=ans.substr(1,ans.length()-2);
                ans="";
            }
        }
        return temp;
    }