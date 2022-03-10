// basic recusion says that a element either can remain single or pair with any elelemnt after it 
// but for counting purpose we can say we have to calculate count of either n-1 elelments or n-1*(count of n-2) elements.
bottom up approach
int mod = (int)1e9 + 7;
   long long int dp[10001];
   
   long long int helper(int n){
       if(n == 1) return (1);
       if(n == 2) return (2);
       
       if(dp[n] != -1) return (dp[n]);
       
       return dp[n] = (helper(n-1) + (n-1)*helper(n-2)) % mod;
   }
   
   int countFriendsPairings(int n){
       memset(dp,-1,sizeof(dp));
       return (int)helper(n);
   }

top down approach
int countFriendsPairings(int n){
       int mod = (int)1e9 + 7;
       long long int dp[n+1];
       dp[1] = 1;
       dp[2] = 2;
       
       for(int i = 3; i <= n; i++){
           dp[i] = (dp[i-1] + (i-1)*dp[i-2]) % mod;
       }
       
       return (int)dp[n];
   }