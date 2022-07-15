//https://practice.geeksforgeeks.org/problems/word-boggle4143/1/?page=1&difficulty[]=0&difficulty[]=1&status[]=unsolved&category[]=Graph&category[]=DFS&sortBy=submissions#
// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
public:
    void dfs(int i,int j,vector<vector<char>> &arr,vector<vector<int>> &ok,set<string> &mp,string temp,int len,string hmm,int idx)
    {
        if(i<0||j<0||i>=arr.size()||j>=arr[0].size()||temp.length()==hmm.length()||temp.length()==len||idx>=hmm.length()||hmm[idx]!=arr[i][j]) return;
        if(ok[i][j]) return;
        temp+=arr[i][j];
        ok[i][j]=1;
        if(temp.size()==hmm.size())
            mp.insert(temp);
        dfs(i+1,j,arr,ok,mp,temp,len,hmm,idx+1);
        dfs(i,j+1,arr,ok,mp,temp,len,hmm,idx+1);
        dfs(i-1,j,arr,ok,mp,temp,len,hmm,idx+1);
        dfs(i,j-1,arr,ok,mp,temp,len,hmm,idx+1);
        dfs(i+1,j+1,arr,ok,mp,temp,len,hmm,idx+1);
        dfs(i+1,j-1,arr,ok,mp,temp,len,hmm,idx+1);
        dfs(i-1,j-1,arr,ok,mp,temp,len,hmm,idx+1);
        dfs(i-1,j+1,arr,ok,mp,temp,len,hmm,idx+1);
        ok[i][j]=0;
    }
	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dict) {
	    int n = board.size();
	    int m = board[0].size();
	    vector<vector<int>> ok(n,vector<int>(m,0));
	    map<char,vector<string>> s;
	    int len = 0;
	    for(auto &value:dict)
	    {
	        if(value.length()>len) len = value.length();
	        s[value[0]].push_back(value);
	    }
	    set<string> mp;vector<string> ans;
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(s.find(board[i][j])!=s.end())
	            {
	                for(auto &value:s[board[i][j]])
	                {
	                        if(mp.find(value)!=mp.end()){ continue;}
	                    	vector<vector<int>> ok(n,vector<int>(m,0));
	                        dfs(i,j,board,ok,mp,"",len,value,0);
	                }

	            }
	        }
	    }
	    
	    for(auto &value:s)
	    {
	        for(auto &val:value.second)
	        {
	            if(mp.find(val)!=mp.end()) ans.push_back(val);
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