//https://leetcode.com/problems/match-substring-after-replacement/submissions/
class Solution {
public:
    
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        //Sliding Window with string matching optimization
        int i=0;int j = 0;
        unordered_map<char,unordered_set<char>> mp;
        for(auto &value:mappings)
        {
             mp[value[0]].insert(value[1]);
        }
        string ans = "";
        int N = s.length();
        while(j<N)
        {
            ans+=s[j];
            if(j-i+1<sub.length())
            {
                j++;
            }
            else
            {
                //operation
                bool flag = true;
                for(int k=0;k<sub.length();k++)
                {
                    if(sub[k]==ans[k])
                    {
                        
                    }
                    else
                    {
                        if(mp.find(sub[k])==mp.end())
                        {
                            flag = false;
                            break;
                        }
                        else
                        {
                            bool a = false;
                            // for(auto &value:mp[sub[k]])
                            // {
                            //     if(value==ans[k])
                            //     {
                            //         a=true;break;
                            //     }
                            // }
                            if(mp[sub[k]].find(ans[k])!=mp[sub[k]].end())
                            {
                                a=true;
                            }
                            if(!a)
                            {
                                flag = false;break;
                            }
                        }
                    }
                }
                if(flag)
                        return true;
                ans.erase(ans.begin()+0);
                i++;
                j++;
            }
        }
        return false;
    }
};