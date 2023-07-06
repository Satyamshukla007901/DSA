//https://practice.geeksforgeeks.org/problems/topological-sort/1
//TC->O(N+E)
//SC->O(N)+O(N)

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	void topoDfs(int node,vector<int> &ok,vector<int> &st,vector<int> adj[])
	{
	    ok[node]  =  1;
	    
	    for(auto &value:adj[node])
	    {
	        if(ok[value]==0)
	        {
	            topoDfs(value,ok,st,adj);
	        }
	    }
	    st.push_back(node);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> ok(V,0);
	   // stack<int> st;
	   vector<int> st;
	    for(int i=0;i<V;i++)
	    {
	        if(ok[i]==0)
	        {
	            topoDfs(i,ok,st,adj);
	        }
	    }
	    
	        
	    reverse(st.begin(),st.end());
	    return st;
	    // code here
	}
};
