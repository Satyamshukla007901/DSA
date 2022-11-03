//https://practice.geeksforgeeks.org/problems/minimum-characters-to-be-added-at-front-to-make-string-palindrome/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int minChar(string str){
        int N = str.length();
        int i =0 ;
        int j = N-1;
        int temp = j;
        int ans = 0;
        while(i<j)
        {
            if(str[i]==str[j])
            {
                i++;
                j--;
            }
            else
            {
                ans++;
                i=0;
                j=--temp;
            }
        }
        return ans;
        //Write your code here
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.minChar(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends