//https://practice.geeksforgeeks.org/problems/smallest-distant-window3132/1#
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    string findSubString(string str)
    {
        int ans = INT_MAX;
        map<char,int> mp;
        for(auto &value:str)
        {
            mp[value]++;
        }
        map<char,int> m2;
        int i = 0;
        int j = 0;int k = 0;
        while(j<str.length())
        {
            m2[str[j]]++;
            if(m2.size()<mp.size())
            {
                j++;
            }
            else if(m2.size()==mp.size())
            {
                if(j-i+1<ans)
                    k=i;
                ans=min(ans,j-i+1);
                // cout<<ans<<" "<<i<<" "<<j<<endl;
                while(m2.size()==mp.size())
                {
                    if(j-i+1<ans)
                        k=i;
                    ans=min(ans,j-i+1);
                    // cout<<ans<<" "<<i<<" "<<j<<endl;
                    m2[str[i]]--;
                    if(m2[str[i]]==0)
                    {
                        m2.erase(str[i]);
                    }
                    i++;
                }
                j++;
            }
            // cout<<ans<<endl;
        }
        // cout<<ans<<endl;
        
        return str.substr(k,ans);
        // Your code goes here   
    }
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str).size() << endl;
    }
    return 0;
}  // } Driver Code Ends