//https://practice.geeksforgeeks.org/problems/hamiltonian-path2522/1/?page=1&difficulty[]=0&difficulty[]=1&status[]=unsolved&category[]=Graph&category[]=DFS&sortBy=submissions#
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    bool dfs(int x,set<int> &s,int N,map<int,vector<int>> &mp)
    {
        if(s.size()==N-1) return true;
        s.insert(x);// visited array can also be taken but in that we have to check in O(N) time 
        for(auto &value:mp[x])
        {
            if(s.find(value)==s.end())
            {
                if(dfs(value,s,N,mp)) return true;
            }
        }
        
        s.erase(x);
        return false;
    }
    bool check(int N,int M,vector<vector<int>> Edges)
    {
        map<int,vector<int>> mp;
        for(auto &value:Edges)
        {
            mp[value[0]].push_back(value[1]);
            mp[value[1]].push_back(value[0]);
        }
        set<int> s;
        for(int i=1;i<=N;i++)
        {
            if(dfs(i,s,N,mp)) return true;
        }
        return false;
        // code here
    }
};
 

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
    	int N,M,X,Y;
    	cin>>N>>M;
    	vector<vector<int>> Edges;
    	for(int i=0;i<M;i++)
    	{
    		cin>>X>>Y;
    		Edges.push_back({X,Y});
    	}
    	Solution obj;
    	if(obj.check(N,M,Edges)){
    		cout<<"1"<<endl;
    	}
    	else
    	cout<<"0"<<endl;
	}
}  // } Driver Code Ends