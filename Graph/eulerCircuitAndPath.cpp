//https://practice.geeksforgeeks.org/problems/euler-circuit-and-path/1/?page=1&difficulty[]=0&difficulty[]=1&status[]=unsolved&category[]=Graph&category[]=DFS&sortBy=submissions#
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	int isEularCircuit(int V, vector<int>adj[]){
	    vector<int> ok(V,0);
	    for(int i=0;i<V;i++)
	    {
	        for(auto &value:adj[i])
	        {
	            ok[value]++;
	        }
	    }
	    int ans = 0;
	    int e = 0,o = 0;
	    for(auto &value:ok)
	    {
	        if(value&1) o++;
	        else e++;
	    }
	    if(e==V) ans = 2;
	    // else if(e==V-2 and o==2) ans =1 ;
	    return ans;
	    // Code here
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		int ans = obj.isEularCircuit(V, adj);
		cout << ans <<"\n";	}
	return 0;
}  // } Driver Code Ends