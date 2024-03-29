//https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#
//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    static bool cmp(Job a,Job b)
    {
        return a.profit>b.profit;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        int maxi = INT_MIN;
         
        
        
        for(int i=0;i<n;i++)
        {    maxi = max(maxi,arr[i].dead);}
        vector<int> ok(maxi,0);
        sort(arr,arr+n,cmp);
        for(int i=0;i<n;i++)
        {
            int j = arr[i].dead-1;
            while(j>=0 and ok[j]!=0)
            {
                j--;
            }
            if(j>=0)
            {
                ok[j] = arr[i].profit;
            }
        }
        int cnt = 0;
        int sum = 0;
        for(auto &value:ok)
        {
            if(value!=0)
            {
                cnt++;
                sum+=value;
            }
        }
        return {cnt,sum};
        // your code here
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends