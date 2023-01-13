//https://practice.geeksforgeeks.org/problems/alien-dictionary/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=alien-dictionary
TC-->O(N*L+K)
SC-->O(K)

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        //calculating no of alphabets
        set<char> s;
        for(int i=0;i<N;i++)
        {
            for(auto &value:dict[i])
            {
                s.insert(value);
            }
        }
        vector<int> adj[s.size()];
        for(int i=0;i<N;i++)
        {
            if(i+1<N)
            {
                string a = dict[i];
                string b = dict[i+1];
                int x = 0;
                int y = 0;
                while(x<a.length() and y<b.length() and a[x]==b[y])
                {
                    x++;
                    y++;
                }
                if(x<a.length() and y<b.length())
                {
                    adj[a[x]-'a'].push_back(b[y]-'a');
                }
            }
        }
        vector<int> in(s.size(),0);
        for(int i=0;i<s.size();i++)
        {
            for(auto &value:adj[i])
            {
                in[value]++;
            }
        }
        queue<int> q;
        string ans = "";
        for(int i=0;i<s.size();i++)
        {
            if(in[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            ans+=('a'+node);
            for(auto &value:adj[node])
            {
                in[value]--;
                if(in[value]==0)
                {
                    q.push(value);
                }
            }
            
        }
        return ans;
        //code here
    }
};

// { Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends