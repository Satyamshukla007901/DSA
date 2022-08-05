//https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void dfs(int x,int y,vector<vector<int>> &arr,string temp,vector<string> &ans,vector<vector<int>> ok)
    {
        if(x<0 or y<0 or x>=arr.size() or y>=arr.size() or ok[x][y] == 1 or arr[x][y]==0) return;
        else if(x==arr.size()-1 and y==arr.size()-1)
        {
            ans.push_back(temp);
            return;
        }
        
        //try out all possible ways
        ok[x][y] = 1;
        dfs(x-1,y,arr,temp+"U",ans,ok);
        dfs(x+1,y,arr,temp+"D",ans,ok);
        dfs(x,y-1,arr,temp+"L",ans,ok);
        dfs(x,y+1,arr,temp+"R",ans,ok);
        ok[x][y] = 0;
    }
    vector<string> findPath(vector<vector<int>> &arr, int n) {
        vector<string> ans;
        if(arr[0][0]==0 or arr[n-1][n-1]==0) return ans;
        vector<vector<int>> ok(n,vector<int>(n,0));
        string temp = "";
        
        dfs(0,0,arr,"",ans,ok);
        return ans;
        // Your code goes here
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends