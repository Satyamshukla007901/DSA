//https://practice.geeksforgeeks.org/problems/find-the-string-in-grid0111/1/?page=1&difficulty[]=0&difficulty[]=1&status[]=unsolved&category[]=Graph&category[]=DFS&sortBy=submissions#
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool dfs(int i,int j,vector<vector<char>> &arr,vector<vector<int>> &ok,int idx,string word,int flag)
    {
        if(i<0||j<0||i>=arr.size()||j>=arr[0].size()||ok[i][j]==1) return false;
        if(idx==word.length()-1)
        {
            return word[idx]==arr[i][j];
        }
        else if(word[idx]!=arr[i][j])
            return false;
        ok[i][j]=1;
        bool res = false;
        if(flag == 1)
        {
            res = res||dfs(i,j+1,arr,ok,idx+1,word,flag);
        }
        else if(flag == 2)
        {
            res = res||dfs(i,j-1,arr,ok,idx+1,word,flag);
        }
        else if(flag == 3)
        {
            res = res||dfs(i+1,j,arr,ok,idx+1,word,flag);
        }
        else if(flag == 4)
        {
            res = res||dfs(i-1,j,arr,ok,idx+1,word,flag);
        }
        else if(flag == 5)
        {
            res = res||dfs(i+1,j+1,arr,ok,idx+1,word,flag);
        }
        else if(flag == 6)
        {
            res = res||dfs(i-1,j+1,arr,ok,idx+1,word,flag);
        }
        else if(flag == 7)
        {
            res = res||dfs(i+1,j-1,arr,ok,idx+1,word,flag);
        }
        else if(flag == 8)
        {
            res = res||dfs(i-1,j-1,arr,ok,idx+1,word,flag);
        }
        ok[i][j]=0;
        
        return res;
        
    }
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	   
	    int n = grid.size();
	    int m = grid[0].size();
	    vector<vector<int>> ans;
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(grid[i][j]==word[0])
	            {
	                bool flag = false;
	                for(int a=1;a<=8;a++)
	                {    
	                    vector<vector<int>> ok(n,vector<int>(m,0));
	                    if(dfs(i,j,grid,ok,0,word,a))
	                    {
	                        flag = true;
	                    }
	                    
	                }
	                if(flag)
	                    ans.push_back({i,j});
	            }
	        }
	    }
	    return ans;
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
	}
	return 0;
}  // } Driver Code Ends