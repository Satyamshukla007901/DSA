//https://practice.geeksforgeeks.org/problems/longest-subsequence-such-that-difference-between-adjacents-is-one4724/1/?page=1&difficulty[]=-1&difficulty[]=0&status[]=unsolved&category[]=Dynamic%20Programming&sortBy=submissions
    int longestSubsequence(int N, int A[])
    {
        int dp[N]={0};//dp carrying the length of seubsequences ending at ith particular index
        for(int i=0;i<N;i++)
        {
            int max = 0;
            for(int j=0;j<i;j++)
            {
                if(abs(A[j]-A[i])==1)
                {
                    if(dp[j]>max)
                        max=dp[j];
                }
            }
            dp[i]=max+1;
        }
        int maxe = 0;
        for(int i=0;i<N;i++)
            maxe = max(maxe,dp[i]);
        return maxe;
        // code here
    }