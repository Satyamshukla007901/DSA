#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define mod 1000000007
#define fasio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fori(i,a,b) for(int i=a;i<b;i++)
#define endl "\n"
#define elif else if
const ll INF=1e17;
const ll NINF=(-1)*INF;
int main() {
    int T;
    cin>>T;
    while(T-->0)
    {
        int R1,W1,C1,R2,W2,C2;
        cin>>R1>>W1>>C1;
        cin>>R2>>W2>>C2;
        if((R1>R2&&W1>W2)||(W1>W2&&C1>C2)||(R1>R2&&C1>C2))
            cout<<"A"<<endl;
        else
            cout<<"B"<<endl;

    }
	// your code goes here
	return 0;
}
