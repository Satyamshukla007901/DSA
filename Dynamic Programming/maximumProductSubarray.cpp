//https://practice.geeksforgeeks.org/problems/maximum-product-subarray3604/1/?page=1&difficulty[]=-1&difficulty[]=1&status[]=unsolved&category[]=Dynamic%20Programming&sortBy=submissions
	long long maxProduct(vector<int> arr, int n) {
	    long long maxe = arr[0];
	    long long  mine = arr[0];
	    long long ans = arr[0];
	    for(int i=1;i<n;i++)
	    {
	        if(arr[i]<0)
	        {
	            swap(maxe,mine);
	        }
	        maxe = max((long long)arr[i],maxe*arr[i]);
	        mine = min((long long)arr[i],mine*arr[i]);
	        ans = max(ans,maxe);
	    }
	    return ans;
	    // code here
	}

// the max xproduct can be botained either multiplying all the positive numbers