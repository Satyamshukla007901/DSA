//https://leetcode.com/problems/merge-intervals/submissions/
// Intituion is We have to cover all the intervals which can be donw just by considering all the cases
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end());
        int l = arr[0][0];
        int r = arr[0][1];
        vector<vector<int>> ans;
        vector<int> temp(2,0);
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i][1]>=l and arr[i][1]<=r) // case 1 : merging [1,4] , [-1,2]
            {
                l = min(l,arr[i][0]);
            }
            else if(arr[i][0]<=r and l<=arr[i][0]) // case 2 : merging [1,4] , [2,6]
            {
                r = max(r,arr[i][1]);
            }
            else if(arr[i][0]<l and arr[i][1]>r) // case 3 : merging [2,6] , [0,7]
            {
                l=arr[i][0];
                r=arr[i][1];
            }
            else if(arr[i][0]>r) // cant be merged so declared as a fixed interval [1,4] [5,8]
            {
                
                temp[0] = l;
                temp[1] = r;
                ans.push_back(temp);
                l=arr[i][0];
                r=arr[i][1];
            }
            else if(arr[i][0]<l) // cant be merged so declared as a fixed interval [5,8] [1,2]
            {
                temp[0] = l;
                temp[1] = r;
                ans.push_back(temp);
                l=arr[i][0];
                r=arr[i][1];
            }
            
        }
        temp[0]=l;temp[1]=r;
        ans.push_back(temp);
        
        return ans;
    }