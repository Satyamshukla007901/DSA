//https://practice.geeksforgeeks.org/problems/steps-by-knight5927/1/?page=1&status[]=unsolved&category[]=Graph&category[]=DFS&sortBy=submissions
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    vector<pair<int,int>> mc = {{2,1},{2,-1},{-1,2},{1,2},{-2,1},{-2,-1},{1,-2},{-1,-2}};
                                
	int minStepToReachTarget(vector<int>&X,vector<int>&Y,int N)
	{
	    int vis[N][N];
	    int lev[N][N];
	    
	    for(int i=0;i<N;i++)
	    {
	        for(int j=0;j<N;j++)
	        {
	            vis[i][j] = 0;
	            lev[i][j] = 1e9+10;
	        }
	    }
	    queue<pair<int,int>> q;
	    q.push({X[0]-1,X[1]-1});
	    vis[X[0]-1][X[1]-1] = 1;
	    lev[X[0]-1][X[1]-1] = 0;
	    while(!q.empty())
	    {
	        auto x = q.front();q.pop();
	        for(auto &value:mc)
	        {
	            int cx = value.first+x.first;
	            int cy = value.second+x.second;
	            if(cx<0||cy<0||cx>=N||cy>=N) continue;
	            
	            if(!vis[cx][cy])
	            {
	                q.push({cx,cy});
	                vis[cx][cy] = 1;
	                lev[cx][cy] = lev[x.first][x.second]+1;
	            }
	        }
	        if(lev[Y[0]-1][Y[1]-1]!=1e9+10) break;
	    }
	    return lev[Y[0]-1][Y[1]-1];
	    // Code here
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends