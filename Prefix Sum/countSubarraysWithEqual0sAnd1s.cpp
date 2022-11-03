//https://practice.geeksforgeeks.org/problems/count-subarrays-with-equal-number-of-1s-and-0s-1587115620/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
// TC O(N)
//Sc O(1)

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
  public:
    //Function to count subarrays with 1s and 0s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        map<int,int> mp;
        mp[0]=1;
        int sum = 0;int cnt = 0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==0) sum+=-1;
            else sum+=1;
            
            // if(sum==0){ cnt+=mp[sum]}
            if(mp.find(sum)!=mp.end())
            {
                cnt+=mp[sum];
                mp[sum]++;
            }
            else
                mp[sum]++;
        }
        return cnt;
        //Your code here
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,i;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution obj;
	cout<< obj.countSubarrWithEqualZeroAndOne(arr, n)<<"\n";
	}
	return 0;
}

// } Driver Code Ends