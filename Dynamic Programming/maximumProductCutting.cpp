//https://practice.geeksforgeeks.org/problems/maximum-product-cutting4522/1/?page=1&difficulty[]=-1&difficulty[]=0&status[]=unsolved&category[]=Dynamic%20Programming&sortBy=submissions#
 top down recursion
 	int solve(int n,vector<int> &len,int l)
	{
	    if(n==0)
	    {
	        return 1;
	    }
	    if(l==0)
	        return 0;
	    
	    if(len[l-1]<=n)
	    {
	        return max(len[l-1]*solve(n-len[l-1],len,l),solve(n,len,l-1));
	    }
	    else
	    {
	        return solve(n,len,l-1);
	    }
	}
	int maxProduct(int n)
	{
        vector<int> l;
        for(int i=1;i<=n;i++)
        {
            l.push_back(i);
        }
        return solve(n,l,l.size());
		// Your code goes here
	}


top down memeoisation
	int solve(int n,vector<int> &len,int l,vector<vector<int>> &dp)
	{
	    if(n==0)
	    {
	        return 1;
	    }
	    if(l==0)
	        return 0;
	    if(dp[l][n]!=-1)
	        return dp[l][n]%10000000007;
	    if(len[l-1]<=n)
	    {
	        return dp[l][n]=(max(len[l-1]*solve(n-len[l-1],len,l,dp),solve(n,len,l-1,dp)))%1000000007;
	    }
	    else
	    {
	        return dp[l][n]=solve(n,len,l-1,dp)%1000000007;
	    }
	}
	int maxProduct(int n)
	{
        vector<int> l;
        for(int i=1;i<n;i++)
        {
            l.push_back(i);
        }
        vector<vector<int>> dp(l.size()+1,vector<int>(n+1,-1));
        return solve(n,l,l.size(),dp)%1000000007;
		// Your code goes here
	}

//bottom up
	int maxProduct(int n)
	{
        vector<int> l;
        for(int i=1;i<n;i++)
        {
            l.push_back(i);
        }
        vector<vector<int>> dp(l.size()+1,vector<int>(n+1,0));
        for(int i=0;i<=l.size();i++)
        {
            dp[i][0]=1;
        }
        for(int j=1;j<=n;j++)
        {
            dp[0][j]=0;
        }
        for(int i=1;i<=l.size();i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(l[i-1]<=j)
                {
                    dp[i][j]=(max((l[i-1]*dp[i][j-l[i-1]]),dp[i-1][j]))%1000000007;
                }
                else
                {
                    dp[i][j]=dp[i-1][j]%1000000007;
                }
                
            }
        }
        return dp[l.size()][n]%1000000007;
		// Your code goes here
	}