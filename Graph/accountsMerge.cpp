//https://practice.geeksforgeeks.org/problems/account-merge/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=account-merge
//TC - 
//SC-
//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class DisjointSet{
    vector<int> rank,parent;
    public:
    DisjointSet(int N)
    {
        rank.resize(N+1,0);
        parent.resize(N+1);
        for(int i=0;i<=N;i++)
        {
            parent[i]=i;
        }
    }
    int findPar(int node)
    {
        if(node==parent[node]) return node;
        return parent[node]=findPar(parent[node]);
    }

    void Union(int u,int v)
    {
        int ult_u  = findPar(u);
        int ult_v = findPar(v);
        if(ult_u == ult_v) return;

        if(rank[ult_u]<rank[ult_v])
        {
            parent[ult_u] = ult_v;
        }
        else if(rank[ult_v]<rank[ult_u])
        {
            parent[ult_v] = ult_u;
        }
        else
        {
            parent[ult_v] = ult_u;
            rank[ult_u]++;
        }
    }
};
class Solution{
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &arr) {
        int N = arr.size();
        DisjointSet d(N);
        vector<vector<string>> ans;
        map<string,int> mp;
        for(int i=0;i<N;i++)
        {
            vector<string> ok = arr[i];
            for(int j=1;j<ok.size();j++)
            {
                 if(mp.find(ok[j])==mp.end())
                 {
                    
                     mp[ok[j]]=i;
                 }
                 else
                 {
                    
                     d.Union(i,mp[ok[j]]);
                    
                 }
            }
        }
        map<int,set<string>> res;
        
        for(int i=0;i<N;i++)
        {
            vector<string> op;
            int p_i = d.findPar(i);
            for(int j=1;j<arr[i].size();j++)
            {
                res[p_i].insert(arr[i][j]);
            }
        }
        for(auto &value:res)
        {
            vector<string> op;
            op.push_back(arr[value.first][0]);
            for(auto &val:value.second) op.push_back(val);
            ans.push_back(op);
        }
        return ans;
        

        // code here
    }
};


//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<vector<string>> accounts;

    for (int i = 0; i < n; i++)
    {
      vector<string> temp;
      int x;
      cin >> x;

      for (int j = 0; j < x; j++)
      {
        string s1;
        cin >> s1;
        temp.push_back(s1);
      }
      accounts.push_back(temp);
    }

    Solution obj;
    vector<vector<string>> res = obj.accountsMerge(accounts);
    sort(res.begin(), res.end());
    cout << "[";
    for (int i = 0; i < res.size(); ++i)
    {
      cout << "[";
      for (int j = 0; j < res[i].size(); j++)
      {
        if (j != res[i].size() - 1)
          cout << res[i][j] << ","
               << " ";
        else
          cout << res[i][j];
      }
      if (i != res.size() - 1)
        cout << "], " << endl;
      else
        cout << "]";
    }
    cout << "]"
         << endl;
  }
}
// } Driver Code Ends