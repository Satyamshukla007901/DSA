//https://leetcode.com/problems/palindrome-partitioning/
    bool isPalin(int l,int r,string s)
    {
        while(l<=r)
        {
            if(s[l]!=s[r])
            {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    void f(int idx,int i,string s,vector<string> &ok,vector<vector<string>> &ans)
    {
        if(i==s.size())
        {
            
            int l = 0 ;
            for(auto &value:ok)
            {
                l+=value.length();
            }
            if(l==s.length())
                ans.push_back(ok);
            return;
        }
        
        if(isPalin(idx,i,s))
        {
            ok.push_back(s.substr(idx,i-idx+1));
            f(i+1,i+1,s,ok,ans);
            ok.pop_back();
        }
        
        f(idx,i+1,s,ok,ans);
        
    }
    vector<vector<string>> partition(string s) {
        vector<string> ok;
        vector<vector<string>> ans;
        f(0,0,s,ok,ans);
        return ans;
    }