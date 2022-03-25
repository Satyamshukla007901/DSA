//https://leetcode.com/problems/remove-duplicate-letters/submissions/
class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        unordered_map<char,int> mp;
        for(auto &value:s)
            mp[value]++;
        stack<char> st;
        unordered_map<char,int> pos;
        for(auto &value:s)
        {
            mp[value]--;
            if(pos[value]==1)
                    continue;
            
            while(!st.empty()&&st.top()>value&&mp[st.top()]>=1)
            {
                pos[st.top()] = 0;
                st.pop();
            }
            pos[value] = 1;
            st.push(value);
            
        }
        s="";
        while(!st.empty())
        {
            s=st.top()+s;
            st.pop();
        }
        return s;
    }
};