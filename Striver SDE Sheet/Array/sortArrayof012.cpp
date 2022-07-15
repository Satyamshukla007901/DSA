//https://leetcode.com/problems/sort-colors/submissions/
        int f = 0;
        int s = a.size()-1;
        while(f<s)
        {
            if(a[f]==0) f++;
            else if(a[s]==1 or a[s]==2)
                s--;
            else
            {
                swap(a[f],a[s]);
                f++;
                s--;
            }
        }
        for(int i=0;i<a.size();i++)
        {
            if(a[i]==1 or a[i]==2)
            {
                f=i;
                break;
            }
        }
        s = a.size()-1;
        while(f<s)
        {
            if(a[f]==1) f++;
            else if(a[s]==2)
                s--;
            else
            {
                swap(a[f],a[s]);
                f++;
                s--;
            }
        }