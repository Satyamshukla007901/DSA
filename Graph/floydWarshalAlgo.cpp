//https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1/?page=1&difficulty[]=0&difficulty[]=1&status[]=unsolved&category[]=Graph&category[]=DFS&sortBy=submissions#
// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    int n = matrix.size();
	    int m = matrix[0].size();
	    vector<vector<int>> ok(n,vector<int>(m,-1));
	    
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(i==j)
	            {
	                ok[i][j]=0;
	            }
	            else
	            {
	                ok[i][j] = matrix[i][j];
	            }
	        }
	    }
	    for(int k=1;k<=n;k++)
	    {
	        for(int i=0;i<n;i++)
	        {
	            for(int j=0;j<m;j++)
	            {
	                if(ok[i][k-1]!=-1 and ok[k-1][j]!=-1)
	                {
	                    if(ok[i][j]!=-1)
	                        ok[i][j] = min(ok[i][j],ok[i][k-1]+ok[k-1][j]);
	                    else
	                        ok[i][j] = ok[i][k-1]+ok[k-1][j];
	                }
	            }
	        }
	    }
	    matrix=ok;
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
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends