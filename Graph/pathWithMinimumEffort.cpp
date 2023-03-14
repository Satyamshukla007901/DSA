//https://practice.geeksforgeeks.org/problems/path-with-minimum-effort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=path-with-minimum-effort
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        pq.push({0,{0,0}});
        int drow[4] = {-1,0,1,0};
        int dcol[4] = {0,1,0,-1};
        while(!pq.empty())
        {
            int d = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            if(x==n-1 and y==m-1) return d;
            pq.pop();
            for(int i=0;i<4;i++)
            {
                int nx = x+drow[i];
                int ny = y+dcol[i];
                if(nx>=0 and nx<n and ny>=0 and ny<m and max(d,abs(heights[x][y]-heights[nx][ny]))<dist[nx][ny])
                {
                    dist[nx][ny] = max(d,abs(heights[x][y]-heights[nx][ny]));
                    pq.push({dist[nx][ny],{nx,ny}});
                }
            }
            
            
        }
        return -1;
        // Code here
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends