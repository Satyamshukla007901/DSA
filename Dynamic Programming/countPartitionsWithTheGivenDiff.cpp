// count partitions of the array with the given difference 
// prerequisite is the count subset sum problem
//code
#include <bits/stdc++.h>
using namespace std;
int countSubsets(vector<int> &vp,int N,int sum)
{
    vector<vector<int>> dp(N,vector<int>(sum+1,0));
    for(int i=0;i<N;i++)
    {
        dp[i][0] = 1;
    }
    if(vp[0]<=sum)
    {
        dp[0][vp[0]]=1;
    }

    for(int i=1;i<N;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            int notPick = dp[i-1][j];
            int pick = 0;
            if(vp[i]<=j)
            {
                pick = dp[i-1][j-vp[i]];
            }
            dp[i][j] = notPick+pick;
        }
    }
    
    return dp[N-1][sum];
}
int countSub(vector<int> &vp,int N,int diff)
{
    int sum = 0;
    for(auto &value:vp)
        sum+=value;
    //edge cases
    if(sum-diff<0||(sum-diff)%2==1)
    {
        return 0;
    }
    //let the two subsets be having sum s1 , s2
    //s1-s2 = D , where D is the difference
    //s1+s2 = Sum, where Sum is total Sum
    //s2 = (Sum-diff)/2
    return countSubsets(vp,N,(sum-diff)/2);

}

int32_t main()
{
    int N;
    cin>>N;
    int diff;
    cin>>diff;
    vector<int> vp(N);
    for(int i=0;i<N;i++)
    {
        cin>>vp[i];
    }
    cout<<countSub(vp,N,diff)<<endl;
    return 0;
}