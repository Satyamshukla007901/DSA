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
        int A1,A2,A3,A4;
        cin>>A1>>A2>>A3>>A4;
        int ans;
        int A[11]={0};
        A[A1]++;
        A[A2]++;
        A[A3]++;
        A[A4]++;
        int ones = 0;int two=0;
        for(int i=1;i<=10;i++)
        {
            if(A[i]==1)
                ones++;
            else if(A[i]==2)
                two++;
        }
        if(ones==4)
            ans=2;
        // else if(ones==2)
        //     ans=1;
        else if((ones==0&&two==2)||(ones==2&&two==1))
            ans=2;
        else if(ones==1)
            ans=1;
        else
            ans=0;
        cout<<ans<<endl;

    }
	return 0;
}
