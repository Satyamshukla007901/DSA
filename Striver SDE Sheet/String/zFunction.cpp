//https://practice.geeksforgeeks.org/problems/8dcd25918295847b4ced54055eae35a8501181c1/1
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    vector<int> zFunc(string &inp)
    {
        vector<int> z(inp.size());
        int left = 0;
        int right = 0;
        for(int k=1;k<inp.length();k++)
        {
            if(k>right)
            {
                left = right = k;
                while(right<inp.length() and inp[right]==inp[right-left]) right++;
                z[k] = right-left;
                right--;
            }
            else
            {
                int k1 = k-left;
                if(z[k1]<right-k+1)
                {
                    z[k] = z[k1];
                }
                else
                {
                    left = k;
                    while(right<inp.length() and inp[right]==inp[right-left]) right++;
                    z[k]=right-left;
                    right--;
                }
            }
        }
        return z;
    }
        vector <int> search(string pat, string txt)
        {
            string nstr = "";
            nstr+=pat;
            nstr+="$";
            nstr+=txt;
            vector<int> ans;
            vector<int> z = zFunc(nstr);
            for(int i=0;i<z.size();i++)
            {
                if(z[i]==pat.length())
                {
                    ans.push_back(i-pat.length()-1+1);
                }
            }
            return ans;
            //code hee.
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if(res.size()==0)
            cout<<"-1 ";
        else
            for (int i : res)
                cout << i << " ";
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends