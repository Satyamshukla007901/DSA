//based on LIS
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};



int maxChainLen(struct val p[],int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		
		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

/*You are required to complete this method*/
#include <vector>
#include <algorithm>
static bool compare(struct val &a,struct val &b)
{
    return a.first<b.first;
}
int maxChainLen(struct val p[],int n)
{
    vector<int> dp(n,1);
    sort(p,p+n,compare);
    for(int i=0;i<n;i++)
    {
        int maxe = 0;
        for(int j=0;j<i;j++)
        {
            if(p[j].second<p[i].first)
            {
                maxe = max(maxe,dp[j]);
            }
            
        }
        dp[i]=maxe+1;
    }
    return *max_element(dp.begin(),dp.end());
//Your code here
}