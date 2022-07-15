//https://practice.geeksforgeeks.org/problems/word-search/1/?page=1&difficulty[]=0&difficulty[]=1&status[]=unsolved&category[]=Graph&category[]=DFS&sortBy=submissions#
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool dfs(int i,int j,vector<vector<char>>& board,vector<vector<int>> &ok,string word,int idx)
    {
        if(i<0||j<0||i>=board.size()||j>=board[0].size()||ok[i][j]==1||idx>word.length())
            return false;
        
        
        if(word[idx]!=board[i][j]) return false;
        if(idx==word.length()-1) return true;
        ok[i][j]=1;
        bool res = dfs(i+1,j,board,ok,word,idx+1) or dfs(i,j+1,board,ok,word,idx+1) or dfs(i-1,j,board,ok,word,idx+1) or dfs(i,j-1,board,ok,word,idx+1);
        //backtrack
        ok[i][j]=0;
        return res;
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> ok(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(word[0]==board[i][j])
                {
                    if(dfs(i,j,board,ok,word,0))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
        // Code here
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends