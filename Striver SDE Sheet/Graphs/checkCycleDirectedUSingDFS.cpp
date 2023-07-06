//https://takeuforward.org/data-structure/detect-cycle-in-a-directed-graph-using-dfs-g-19/
//TC->O(V+E)+O(V)
//SC->O(2N)
bool dfsCheck(int node,vector<int> adj[],int vis[],int DFS[])
{
    vis[node] = 1;
    DFS[node] = 1;
    for(auto &value:adj[node])
    {
        if(!vis[value])
        {
            if(dfs(value,adj,vis,DFS)) return true;
        }
        else if(DFS[value])
        {
            return true;
        }
    }
    DFS[node] = 0;
    return false;
}
bool isCycle(int V,vector<int> adj[])
{
    int vis[V] = {0};
    int DFS[V] = {0};

    for(int i=0;i<V;i++)
    {
        if(!vis[i])
        {
            if(dfsCheck(i,adj,vis,DFS))
            {
                return true;
            }
        }
    }
    return false;
}

