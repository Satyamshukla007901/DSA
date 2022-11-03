//https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1
//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        /*  TC --> O(N^2)
        for(int i=0;i<n;i++)
        {
            int cnt = 0;int cnt1 = 0;
            for(int j=0;j<n;j++)
            {
                if(j!=i and M[j][i]==1)
                {
                    cnt++;
                }
                if(M[i][j]==1)
                {
                    cnt1++;
                }
            }
            
            if(cnt==n-1 and cnt1==0)
            {
                return i;
            }
        }
        
        return -1;*/
        
        int i = 0;
        int j = n-1;
        while(i<j)
        {
            if(M[j][i]==1)
            {
                j--;
            }
            else 
                i++;
        }
        int C = i;
        for(int i=0;i<n;i++)
        {
            if(i!=C and (M[i][C]==0||M[C][i]==1))
            {
                return -1;
            }
        }
        return C;
        
        
        // code here 
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends