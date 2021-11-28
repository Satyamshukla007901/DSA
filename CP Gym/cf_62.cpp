#include <bits/stdc++.h>
using namespace std;
#define LIMIT 1000000
long long i, j;
long long prime_flag[LIMIT];
void calculate_prime_flag(){
    prime_flag[0] = prime_flag[1] = 1;
    for(i=2;i<LIMIT;i++){
        if (prime_flag[i]==0){
            for(j=i*i;j<LIMIT;j+=i){
                prime_flag[j] = 1;
            }
        }
    }
}
int32_t main()
{
    int n,a,b,c;
    cin>>n>>a>>b>>c;
    int ans = INT_MIN;
    for(int i=0;i*a<=n;i++)
    {
        for(int j=0;a*i+b*j<=n;j++)
        {
            int rem = n-a*i-b*j;
            if(rem%c==0)
            {
                ans=max(ans,i+j+(rem/c));
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}