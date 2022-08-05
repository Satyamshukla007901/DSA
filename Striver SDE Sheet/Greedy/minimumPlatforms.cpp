//https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#
    int findPlatform(int arr[], int dep[], int n)
    {
        sort(arr,arr+n);
        sort(dep,dep+n);
        
        int cnt = 1;
        int ans = 1;
        int i = 0;int j = 1;
        while(j<n)
        {
            if(arr[j]>dep[i])
            {
                cnt--;
                i++;
            }
            else
            {
                cnt++;
                j++;
            }
            ans = max(ans,cnt);
        }
        return ans;
    	// Your code here
    }