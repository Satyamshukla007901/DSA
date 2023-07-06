//https://takeuforward.org/data-structure/topological-sort-bfs/
//TC->O(N+E)
//SC->O(N)

queue<int> q;
vector<int> ind(V,0);

for(int i=0;i<V;i++)
{
    for(auto &value:adj[i])
    {
        ind[value]++;
    }
}

for(int i=0;i<V;i++)
{
    if(ind[i]==0)
    {
        q.push(i);
    }
}


vector<int> ans;
while(!q.empty())
{
    int node = q.front();
    q.pop();
    ans.push_back(node);
    for(auto &value:adj[node])
    {
        ind[value]--;
        if(ind[value]==0)
        {
            q.push(value);
        }
    }
}
return ans;