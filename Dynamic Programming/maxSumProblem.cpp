//https://practice.geeksforgeeks.org/problems/maximum-sum-problem2211/1/?page=1&difficulty[]=-1&difficulty[]=0&status[]=unsolved&category[]=Dynamic%20Programming&sortBy=submissions
        int solve(int n)
        {
            if(n<2)
                return n;
            int a = solve(n/2);
            int b = solve(n/3);
            int c = solve(n/4);
            return max(n,a+b+c);
        }
        int maxSum(int n)
        {
            return solve(n);
            //code here.
        }


        int solve(int n,vector<int> &dp)
        {
            if(n<2)
                return dp[n]=n;
            if(dp[n]!=-1)
                return dp[n];
            int a = solve(n/2,dp);
            int b = solve(n/3,dp);
            int c = solve(n/4,dp);
            return dp[n]=max(n,a+b+c);
        }
        int maxSum(int n)
        {
            vector<int> dp(n+1,-1);
            return solve(n,dp);
            //code here.
        }