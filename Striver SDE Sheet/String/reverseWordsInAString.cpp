//https://leetcode.com/problems/reverse-words-in-a-string/
// TC--> O(N)
//SC--> O(1)
class Solution {
public:
    string reverseWords(string s) {
        // vector<string> ok;
        string ans = "";
        string word = "";
        for(auto &value:s)
        {
            if(value==' ')
            {
                if(word!="")
                {
                    // ok.push_back(word);
                    ans = word+" "+ans;
                }
                word = "";
            }
            else
            {
                word+=value;
            }
        }
        if(word!="")
        {
            ans = word+" "+ans;
            // ok.push_back(word);
        }
        // reverse(ok.begin(),ok.end());
        
        // for(auto &value:ok){ ans+=value;ans+=" ";}
        
        ans = ans.substr(0,ans.length()-1);
        return ans;
    }
};