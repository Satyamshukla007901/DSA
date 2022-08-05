//https://leetcode.com/problems/longest-substring-without-repeating-characters/submissions/
        int ans = 0;
        map<char,int> mp;
        int i = 0;
        int j = 0;
        while(j<s.length())
        {
            mp[s[j]]++;
            if(mp.size()==j-i+1)
            {
                ans =  max(ans,j-i+1);j++;
            }
            else if(mp.size()<j-i+1)
            {
                while(mp.size()<j-i+1)
                {
                    mp[s[i]]--;
                    if(mp[s[i]]==0)
                         mp.erase(s[i]);
                    i++;
                }
                if(mp.size()==j-i+1) ans = max(ans,j-i+1);
                j++;
            }
        
        }
        return ans;
    }