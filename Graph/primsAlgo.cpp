//https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1/#
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int> p(V,-1);
        vector<int> key(V,INT_MAX);
        vector<bool> mst(V,false);
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        key[0]=0;
        p[0]=-1;
        pq.push({0,0});
        
        while(!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();
            
            mst[u]=true;
            
            for(auto &value:adj[u])
            {
                if(mst[value[0]]==false and value[1]<key[value[0]])
                {
                    key[value[0]] = value[1];
                    p[value[0]] = u;
                    pq.push({key[value[0]],value[0]});
                }
            }
        }
        int sum = 0;
        for(auto &value:key)
        {
            sum+=value;
        }
        return sum;
        // code here
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends