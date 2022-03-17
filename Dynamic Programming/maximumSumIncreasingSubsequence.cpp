https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1#



// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int a[], int n)  
	{ 
    
    vector<int> sum(n,0);
    for (int i = 0; i < n; i++)
    {
        int ok = 0;
        for (int j = 0; j < i; j++)
        {
            if (a[i] > a[j])
            {
                
                if(sum[j]>ok)
                    ok=sum[j];
            }
        }
        sum[i] = ok+a[i];
    }
   
    int hmm = 0;
    for(int i=0;i<n;i++)
    {
        if(sum[i]>=hmm)
        {
         
            hmm = sum[i];
        }
    }
    return hmm;
	    // Your code goes here
	}  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends