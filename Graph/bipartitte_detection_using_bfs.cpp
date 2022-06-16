//https://practice.geeksforgeeks.org/problems/bipartite-graph/1/
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> vis(V,0);
	    vector<int> c(V,0);
	    for(int i=0;i<V;i++)
	    {
	        if(vis[i]==0)
	        {
	                queue<pair<int,int>> q;
	                q.push({i,-1});
	                c[i]=1;
	                vis[i]=1;
	                while(!q.empty())
	                {
	                    auto node = q.front().first;
	                    
	                    auto par = q.front().second;
	                    q.pop();
	                    for(auto &value:adj[node])
	                    {
	                        if(vis[value]==0)
	                        {
	                            vis[value]=1;
	                            q.push({value,node});
	                            if(c[node]==1)
	                            {
	                                c[value]=2;
	                            }
	                            else if(c[node]==2)
	                            {
	                                c[value]=1;
	                            }
	                        }
	                        else
	                        {
	                            if(c[value]==c[node])
	                            {
	                                return false;
	                            }
	                        }
	                    }
	                }
	        }
	    }
        
	    return true;
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
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends