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
bool check(long long X)
{
    double value = sqrt(X);
    return value==int(value);
}
int main()
{
    calculate_prime_flag();
    long long N;
    cin >> N;
    while (N-- > 0)
    {
        long long X;
        cin >> X;
        // cout<<prime_flag[(int(sqrt(X)))]<<endl;
        if(X!=4&&X%2==0)
        {
            cout<<"NO"<<endl;
        }
        else if(X!=1&&(check(X))&&prime_flag[(int(sqrt(X)))]==0)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}