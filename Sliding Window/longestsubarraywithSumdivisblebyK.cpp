//https://practice.geeksforgeeks.org/problems/longest-subarray-with-sum-divisible-by-k1259/1
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    unordered_map<int,int> mp;
	    mp[0]=-1;
	    int sum =  0;
	    int maxi = 0;
	    for(int i=0;i<n;i++)
	    {
	        sum+=arr[i];
	        int rem = sum%k;
	        if(rem<0)
	        {
	            rem+=k;
	        }
	        if(mp.find(rem)!=mp.end())
	        {
	            maxi = max(maxi,i-mp[rem]);
	        }
	        else if(mp.find(rem)==mp.end())
	            mp[rem]=i;
	    }
	    return maxi;
	    // Complete the function
	}