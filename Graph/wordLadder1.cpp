//https://practice.geeksforgeeks.org/problems/word-ladder/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=word-ladder
TC-O(N*M*26*logN)
SC-O(N)
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string s, string t, vector<string>& word) {
        queue<pair<string,int>> q;
        q.push({s,1});
        int ans = 0;
        set<string> st;
        for(auto &value:word) st.insert(value);
        st.erase(s);
        while(!q.empty())
        {
            string str = q.front().first;
            int dist = q.front().second;
            q.pop();
            if(str==t)
            {
                
                return dist;
            }
            for(int i=0;i<str.length();i++)
            {
                string ok=str;
                for(char ch='a';ch<='z';ch++)
                {
                    ok[i]=ch;
                    if(st.find(ok)!=st.end())
                    {
                        st.erase(ok);
                        q.push({ok,dist+1});
                    }
                }
            }
        }
        return 0;
        // Code here
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends