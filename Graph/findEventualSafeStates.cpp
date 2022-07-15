//https://leetcode.com/problems/find-eventual-safe-states/submissions/
class Solution {
public:
    void topo(int x,vector<vector<int>>& graph,vector<int> &visi,int V,vector<int> &ok)
    {
        visi[x]=1;
        for(auto &value:graph[x])
        {
            if(visi[value]==0)
            {
                topo(value,graph,visi,V,ok);
            }
        }
        ok.push_back(x);
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int N = graph.size();
        vector<int> od(N,0);
        for(int i=0;i<N;i++)
        {
            for(auto &value:graph[i])
            {
                od[i]++;
            }
        }
        vector<int> ans;
        set<int> s;
        vector<int> ok(N,0);
        vector<int> temp;
        for(int i=0;i<N;i++)
        {
            if(ok[i]==0)
            {
                topo(i,graph,ok,N,temp);
            }
        }
        
        for(auto &i:temp)
        {
            if(od[i]==0)
            {
                s.insert(i);
                
            }
            else
            {
                bool flag = true;
                for(auto &value:graph[i])
                {
                    if(ok[value] and s.find(value)==s.end())
                    {
                        flag = false;break;
                    }
                }
                if(flag)
                {
                    s.insert(i);
                }
            }
        }
        for(auto &value:s) ans.push_back(value); 
        return ans;
    }
};