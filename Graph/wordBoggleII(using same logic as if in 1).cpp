//https://practice.geeksforgeeks.org/problems/72cf44eabd18006810efad06fbb623a0682acee2/1/?page=1&difficulty[]=0&difficulty[]=1&status[]=unsolved&category[]=Graph&category[]=DFS&sortBy=submissions
// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
public:
    vector<vector<int>> mv = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
    bool dfs(int i,int j,vector<vector<char>>& board,vector<vector<int>> &ok,string word,int idx)
    {
        if(i<0||j<0||i>=board.size()||j>=board[0].size()||ok[i][j]==1||idx>word.length())
            return false;
        
        
        if(word[idx]!=board[i][j]) return false;
        if(idx==word.length()-1) return true;
        ok[i][j]=1;
        bool res = false;
        // dfs(i+1,j,board,ok,word,idx+1) or dfs(i,j+1,board,ok,word,idx+1) or dfs(i-1,j,board,ok,word,idx+1) or dfs(i,j-1,board,ok,word,idx+1);
        //backtrack
        for(auto &value:mv)
            res = res or dfs(i+value[0],j+value[1],board,ok,word,idx+1);
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
	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) {
	    vector<string> ans;
	    set<string> s;
	    for(auto &value:dictionary)
	    {
	        if(isWordExist(board,value) and s.find(value)==s.end())
	        {
	            ans.push_back(value);
	            s.insert(value);
	        }
	    }
	   
	    return ans;
	    // Code here
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> dictionary;
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }
        
        int R, C;
        cin >> R >> C;
        vector<vector<char> > board(R);
        for (int i = 0; i < R; i++) {
            board[i].resize(C);
            for (int j = 0; j < C; j++) cin >> board[i][j];
        }
        Solution obj;
        vector<string> output = obj.wordBoggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
        }
        cout << endl;
    }
}
  // } Driver Code Ends