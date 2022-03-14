//https://practice.geeksforgeeks.org/problems/sum-of-all-substrings-of-a-number-1587115621/1/?page=1&difficulty[]=-1&difficulty[]=0&status[]=unsolved&category[]=Dynamic%20Programming&sortBy=submissions
    long long sumSubstrings(string s){
        
        int l = s.length();
        vector<long long> dp(l);
        dp[0]=(s[0]-'0');
        long long sum = dp[0]%1000000007;
        for(int i=1;i<l;i++)
        {
            dp[i]=((i+1)*(s[i]-'0')+10*dp[i-1])%1000000007;
            sum+=dp[i]%1000000007;
           
        }
        return sum%1000000007;
        // your code here
    }

    /// based on the recurrence relation that 
    //sum of substringss equal to sum of subsrting ending with that particular digit [i]
    //sum[i] = sum[i-1]*10 + digit[i]*(i+1);