//https://practice.geeksforgeeks.org/problems/minimum-swaps/1/?page=1&difficulty[]=0&difficulty[]=1&status[]=unsolved&category[]=Graph&category[]=DFS&sortBy=submissions
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    int N = nums.size();
	    vector<pair<int,int>> ok;
	    for(int i=0;i<N;i++)
	    {
	        ok.push_back({nums[i],i});
	    }
	    sort(ok.begin(),ok.end());
	    int ans = 0;
	    vector<int> vis(N,0);
	    for(int i=0;i<N;i++)
	    {
	        if(vis[i]==0 and nums[i]!=ok[i].first)
	        {
	            int cycle = 0;
	            int j = i;
	            while(vis[j]==0)
	            {
	                vis[j]=1;
	                cycle++;
	                j=ok[j].second;
	            }
	            ans+=cycle-1;
	        }
	    }
	    return ans;
	    // Code here
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends