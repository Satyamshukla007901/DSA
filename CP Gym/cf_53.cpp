#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int32_t main()
{
    int T;
    cin>>T;
    while(T-->0)
    {
        long long A,B,C;
        cin>>A>>B>>C;
        cout<<max(0LL,-A+max(B,C)+1)<<" "<<max(0LL,-B+max(A,C)+1)<<" "<<max(0LL,-C+max(A,B)+1)<<endl;
    }
    return 0;
}