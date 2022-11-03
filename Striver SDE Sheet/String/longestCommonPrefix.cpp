//https://leetcode.com/problems/longest-common-prefix/submissions/
        // TC-->O(N^2) Sc-->O(1)s
        if(strs.size()==0) return "";
        
        string pre = strs[0];
        for(int i=1;i<strs.size();i++)
        {
            while(strs[i].find(pre)==string::npos or (strs[i].find(pre)!=string::npos and strs[i].find(pre)!=0))
            {
                pre = pre.substr(0,pre.length()-1);
            }
            
        }
        return pre;