//https://practice.geeksforgeeks.org/problems/word-ladder-ii/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=word-ladder-ii
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string s, string t, vector<string>& word) {
        vector<vector<string>> ans;
        queue<vector<string>>  q;
        q.push({s});
        set<string> st;
        for(auto &value:word)
        {
            st.insert(value);
        }
        while(!q.empty())
        {
            vector<string> ok = q.front();
            q.pop();
            string temp = ok[ok.size()-1];
            if(st.find(temp)!=st.end()) st.erase(temp);
            
            if(temp==t)
            {
                if(ans.size()==0)
                    ans.push_back(ok);
                else if(ans[0].size()==ok.size())
                    ans.push_back(ok);
            }
            else
            {
                string re = temp;
                for(auto &value:temp)
                {
                    
                    for(char ch='a';ch<='z';ch++)
                    {
                        value=ch;
                        if(st.find(temp)!=st.end())
                        {
                            ok.push_back(temp);
                            q.push(ok);
                            ok.pop_back();
                        }
                    }
                    temp=re;
                }
            }
        }
        return ans;
        // code here
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

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
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends