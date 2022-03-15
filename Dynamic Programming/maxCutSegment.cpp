//https://practice.geeksforgeeks.org/problems/cutted-segments1642/1/?page=1&difficulty[]=-1&difficulty[]=1&status[]=unsolved&category[]=Dynamic%20Programming&sortBy=submissions#
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int solve(int n,int x,int y,int z,vector<int> &dp)
    {
        if(n==0)
        {
            return dp[n]=0;
        }
        if(n<0)
        {
            return INT_MIN;
        }
        if(dp[n]!=-1)
            return dp[n];
        int a,b,c,d;
        a=1+solve(n-x,x,y,z,dp);
        b=1+solve(n-y,x,y,z,dp);
        c=1+solve(n-z,x,y,z,dp);
        return dp[n]=max(a,max(b,c));
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int> dp(n+1,-1);
        // solve(n,x,y,z,dp);
        // if(dp[n]<0)
        //     return 0;
        // return dp[n];
        
        
        dp[0]=0;
        for(int i=1;i<=n;i++)
        {
            int a=INT_MIN,b=INT_MIN,c=INT_MIN;
            if(i-x>=0)
            {
                a=dp[i-x]+1;
            }
            if(i-y>=0)
            {
                b=dp[i-y]+1;
            }
            if(i-z>=0)
            {
                c=dp[i-z]+1;
            }
            dp[i]=max(a,max(b,c));
        }
        if(dp[n]<0)
            return 0;
        return dp[n];
        //Your code here
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends