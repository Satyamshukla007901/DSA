//https://leetcode.com/problems/permutation-sequence/submissions/
        int fact = 1;
        vector<int> arr;
        for(int i=1;i<n;i++)
        {
            fact = fact*i;
            arr.push_back(i);
        }
        arr.push_back(n);
        string ans = "";
        k--;
        while(1)
        {
            ans = ans+to_string(arr[k/fact]);
            arr.erase(arr.begin()+k/fact);
            if(arr.size()==0) break;
            k%=fact;
            fact = fact/arr.size();
        }
        
        return ans;