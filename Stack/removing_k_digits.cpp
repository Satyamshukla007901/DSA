//https://leetcode.com/problems/remove-k-digits/submissions/
class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k==num.length())
                return "0";
        else if(k==0)
                return num;
        
        stack<char> st;
        for(auto &value:num)
        {
            while(!st.empty()&&k>0&&value<st.top())
            {
                st.pop();
                k--;
            }
            st.push(value);
        }
        while(!st.empty()&&k>0)
        {        st.pop();k--;}
        string ans = "";
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        string ok="";
        int i;
        for(i=0;i<ans.length();i++)
        {
            if(ans[i]!='0')
                    break;
        }
        for(int j=i;j<ans.length();j++)
                ok+=ans[j];
        if(ok=="") 
            return "0";
        return ok;
        
        
    }
};