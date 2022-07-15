//https://practice.geeksforgeeks.org/problems/circle-of-strings4530/1
// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution
{
    public:
    void dfs(char ch,unordered_map<char,bool> &ok,map<char,vector<char>> &mp)
    {
        ok[ch] = true;
        for(auto &value:mp[ch])
        {
            if(ok[value]==false)
            {
                dfs(value,ok,mp);
            }
        }
    }
    int isCircle(int N, vector<string> A)
    {
        map<char,vector<char>> mp;
        unordered_map<char,int> in;
        unordered_map<char,int> out;
        for(auto &value:A)
        {
            mp[value[0]].push_back(value[value.length()-1]);
            out[value[0]]++;
            in[value[value.length()-1]]++;
        }
        for(char ch = 'a';ch<='z';ch++)
        {
            if(in[ch]!=out[ch]) return false;
        }
        unordered_map<char,bool> ok;
        dfs(A[0][0],ok,mp);
        
        for(char ch='a';ch<='z';ch++)
        {
            if(in[ch]!=0 and ok[ch]==false)
            {
                return false;
            }
        }
        return true;
        // code here
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<string> A;
        string s;
        
        for(int i = 0;i < N; i++)
        {
            cin>>s;
            A.push_back(s);
        }
        
        Solution ob;
        cout<<ob.isCircle(N, A)<<endl;
    }
    return 0;
}  // } Driver Code Ends