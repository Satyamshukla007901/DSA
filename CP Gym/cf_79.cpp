#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define mod 1000000007
#define satyam ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fori(i,a,b) for(int i=a;i<b;i++)
#define endl "\n"
#define elif else if
const ll INF=1e17;
const ll NINF=(-1)*INF;
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
int main() {
    satyam;
    ll T;
    cin>>T;
    while(T-->0)
    {
        ll N;
        cin>>N;
        cout<<(N-2)*(N-1) + 1<<endl;
    }
	// your code goes here
	return 0;
}
