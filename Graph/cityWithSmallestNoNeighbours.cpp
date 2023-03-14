//https://practice.geeksforgeeks.org/problems/city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=city-with-the-smallest-number-of-neighbors-at-a-threshold-distance
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges,
                 int K) {
                    vector<vector<int>> arr(n,vector<int>(n,1e9));
                    for(int i=0;i<m;i++)
                    {
                        arr[edges[i][0]][edges[i][1]] = edges[i][2];
                        arr[edges[i][1]][edges[i][0]] = edges[i][2];
                    }
                    
                    for(int i=0;i<n;i++)
                    {
                        arr[i][i]=0;
                    }
                    
                    for(int k=0;k<n;k++)
                    {
                        for(int i=0;i<n;i++)
                        {
                            for(int j=0;j<n;j++)
                            {
                                arr[i][j] = min(arr[i][j],arr[i][k]+arr[k][j]);
                            }
                            
                        }
                    }
                    for(int i=0;i<n;i++)
                    {
                        for(int j=0;j<n;j++)
                        {
                            if(arr[i][j]==1e9)
                            {
                                arr[i][j]=-1;
                            }
                        }
                    }
                    // for(int i=0;i<n;i++)
                    // {
                    //     for(int j=0;j<n;j++)
                    //     {
                    //         cout<<arr[i][j]<<" ";
                    //     }
                    //     cout<<endl;
                    // }
                    int mini = INT_MAX;
                    int ans = n-1;
                    for(int i=0;i<n;i++)
                    {
                        int cnt = 0;bool flag = true;
                        for(int j=0;j<n;j++)
                        {
                            if(arr[i][j]<=K and arr[i][j]!=-1)
                            {
                                flag = false;
                                cnt++;
                            }
                        }
                        
                        if(cnt<=mini and !flag)
                        {
                            mini=cnt;
                            ans = i;
                        }
                    }
                    
                    return ans;
                    
                    
                    
                 }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends