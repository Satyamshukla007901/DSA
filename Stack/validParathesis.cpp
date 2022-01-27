//https://leetcode.com/problems/valid-parenthesis-string/
bool checkValidString(string s)
{
    stack<char> st;
    stack<char> op;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '*')
        {
            op.push(s[i]);
        }
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else
        {
            if (st.empty() && op.empty())
            {
                return false;
            }
            else if (st.empty() && (!op.empty()))
            {
                op.pop();
            }
            else if ((!st.empty()) && op.empty())
            {
                st.pop();
            }
            else
            {
                st.pop();
            }
        }
    }
    while (!st.empty())
        st.pop();
    while (!op.empty())
        op.pop();
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] == '*')
        {
            op.push(s[i]);
        }
        else if (s[i] == ')')
        {
            st.push(s[i]);
        }
        else
        {
            if (st.empty() && op.empty())
            {
                return false;
            }
            else if (st.empty() && (!op.empty()))
            {
                op.pop();
            }
            else if ((!st.empty()) && op.empty())
            {
                st.pop();
            }
            else
            {
                st.pop();
            }
        }
    }
    return true;
}