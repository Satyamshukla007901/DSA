//https://leetcode.com/problems/longest-string-chain/submissions/
class Solution {
public:
    bool compare(string &s1,string &s2)
    {
        if(s1.length() != s2.length()+1) return false;
        
        int i = 0;int j =0;int cnt = 0;
        while(i<s1.length())
        {
            if(s1[i]==s2[j])
            {
                i++;j++;
            }
            else
            {    cnt++;i++;}
        }
        if(cnt==1) return true;
        return false;
        
    }
    static bool cmp(string &s1,string &s2)
    {    return s1.length()<s2.length();}
    int longestStrChain(vector<string>& s) {
       sort(s.begin(),s.end(),cmp);
        int maxi = INT_MIN;
        vector<int> dp(s.size(),1);
        for(int i=0;i<s.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(compare(s[i],s[j]) and dp[j]+1>dp[i])
                {
                    dp[i]=dp[j]+1;
                }
            }
            maxi = max(maxi,dp[i]);
        }
        return maxi;
        
    }
};