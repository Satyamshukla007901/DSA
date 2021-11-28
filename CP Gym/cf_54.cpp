#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
long long res(string S,string B)
{
    long long ans=0;
    long long temp = S.length();
    string help = B;
    while(S.length()>0 and B.length()>0)
    {
        if(S.back()==B.back())
        {
            B.pop_back();

        }
        else
        {
            ans++;
        }
        S.pop_back();
    }
    if(B.length()==0)
        return ans;
    return temp;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T-->0)
    {
        string S;
        cin>>S;
        if(S.length()<2)
        {
            cout<<S.length()<<endl;
        }
        else
        {
            cout<<min(res(S,"00"),min(res(S,"25"),min(res(S,"50"),res(S,"75"))))<<endl;
        }
    }
    return 0;
}