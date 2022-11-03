//https://practice.geeksforgeeks.org/problems/maximum-of-minimum-for-every-window-size3453/1
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n)
    {
        vector<int> l(n);
        vector<int> r(n);
        stack<int> st;
        //NSL
        for(int i=0;i<n;i++)
        {
            while(!st.empty() and arr[st.top()]>=arr[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                l[i] = -1;
            }
            else
            {
                l[i] = st.top();
            }
            st.push(i);
        }
        
        while(!st.empty()) st.pop();
        //NSR
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() and arr[st.top()]>=arr[i]) st.pop();
            
            if(st.empty())
            {
                r[i] = -1;
            }
            else
            {
                r[i] = st.top();
            }
            st.push(i);
        }
        vector<int> ans(n+1,0);
        for(int i=0;i<n;i++)
        {
            int a = l[i];
            
            int b = r[i];
            if(a!=-1 and b!=-1)
            {
                ans[r[i]-l[i]-1] = max(ans[r[i]-l[i]-1],arr[i]);
            }
            else if(a!=-1)
            {
                ans[n-a-1] = max(ans[n-a-1],arr[i]);
            }
            else if(b!=-1)
            {
                ans[b] = max(ans[b],arr[i]);
            }
            else
            {
                ans[n] = max(ans[n],arr[i]);
            }
        }
        ans.erase(ans.begin());
        for(int i=n-2;i>=0;i--)
        {
            
                ans[i] = max(ans[i+1],ans[i]);
            
        }
        return ans;
        
        // Your code here
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        vector <int> res = ob.maxOfMin(a, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends