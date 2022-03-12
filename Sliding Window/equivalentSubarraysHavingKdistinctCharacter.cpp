//https://practice.geeksforgeeks.org/problems/equivalent-sub-arrays3731/1#
Find the number of distinct elements in the entire array. Let this number be k <= N. Initialize Left = 0, Right = 0 and window = 0. 
 
Increment right until the number of distinct elements in the range [Left=0, Right] is equal to k(or window size would not equal to k), let this right be R1. Now, since the sub-array [Left = 0, R1] has k distinct elements, so all the sub-arrays starting at Left = 0 and ending after R1 will also have k distinct elements. Thus, add N-R1+1 to the answer because [Left.. R1], [Left.. R1+1], [Left.. R1+2] … [Left.. N-1] contains all the distinct numbers. 
 
Now keeping R1 same, increment left. Decrease the frequency of the previous element i.e., arr[0], and if its frequency becomes 0, decrease the window size. Now, the sub-array is [Left = 1, Right = R1]. 
 
Repeat the same process from step 2 for other values of Left and Right till Left < N. 
    int solve(int arr[],int n,int k)
    {
        map<int,int> mp;
        int i = 0;
        int j = 0;
        int ans = 0;
        for(j=0;j<n;j++)
        {
            mp[arr[j]]++;
            if(mp.size()==k)
            {
                ans+=n-j;
            }
            while(mp.size()>=k&&i<=j)
            {
                mp[arr[i]]--;
                if(mp[arr[i]]==0)
                    mp.erase(arr[i]);
                if(mp.size()==k)
                {
                    ans+=n-j;
                }
                i++;
            }
        }
        return ans;
        
    }
    int countDistinctSubarray(int arr[], int n)
    {
        set<int> s;
        for(int i=0;i<n;i++)
        {
            s.insert(arr[i]);
        }
        int k = s.size();
        
        return solve(arr,n,k);
        //code here.
    }