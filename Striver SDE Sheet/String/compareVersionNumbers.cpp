//https://leetcode.com/problems/compare-version-numbers/submissions/
// TC-->O(N+M)
// SC-->O(N)

        vector<string> ok1;
        vector<string> ok2;
        
        string temp = "";
        for(auto &value:version1)
        {
            if(value!='.')
            {
                temp+=value;
            }
            else
            {
                ok1.push_back(temp);temp = "";
            }
        }
        if(temp!="") ok1.push_back(temp);
        temp = "";
        for(auto &value:version2)
        {
            if(value!='.')
            {
                temp+=value;
            }
            else
            {
                ok2.push_back(temp);
                temp = "";
            }
        }
        if(temp!="") ok2.push_back(temp);
        /*adding zeroes to 0 revisions*/
        if(ok1.size()<ok2.size())
        {
            while(ok1.size()<ok2.size()) ok1.push_back("0");
        }
        else
        {
            while(ok2.size()<ok1.size()) ok2.push_back("0");
        }
        for(int i=0;i<ok1.size();i++)
        {
            
            if(stoi(ok1[i])<stoi(ok2[i]))
            {
                return -1;
            }
            else if(stoi(ok1[i])>stoi(ok2[i]))
            {
                return 1;
            }
        }
        return 0;


// TC-->O(N+M)
// SC-->(1)

        int i=0;
        int j = 0;
        int n = version1.size();
        int m = version2.size();
        while(i<n or j<m)
        {
            int ok1=0,ok2=0;
            string temp  = "";
            while(i<n and version1[i]!='.')
            {
                temp+=version1[i];i++;
            }
            i++;
            if(temp!="")
                ok1 = stoi(temp);
            temp = "";
            while(j<m and version2[j]!='.')
            {
                temp+=version2[j];
                j++;
            }
            j++;
            if(temp!="")
                ok2 = stoi(temp);
            
            if(ok1<ok2) return -1;
            else if(ok1>ok2) return 1;
        }
        return 0;