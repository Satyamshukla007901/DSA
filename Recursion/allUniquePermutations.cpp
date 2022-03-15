//https://practice.geeksforgeeks.org/problems/all-unique-permutations-of-an-array/1
    void solve(vector<int> &arr,int i,int n,set<vector<int>> &s)
    {
        if(i==n)
        {
            s.insert(arr);
            return;
        }
        for(int x = i;x<n;x++)
        {
            swap(arr[x],arr[i]);
            solve(arr,i+1,n,s);
            swap(arr[x],arr[i]);
        }
    }
    vector<vector<int>> uniquePerms(vector<int> arr ,int n) {
        set<vector<int>> s;
        
        solve(arr,0,n,s);
        vector<vector<int>> ans;
        for(auto &value:s)
        {
            ans.push_back(value);
        }
        sort(ans.begin(),ans.end());
        return ans;
        // code here
    }