#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
    int T;
    cin>>T;
    while(T-->0)
    {
        int N;
        cin>>N;
        string S;
        cin>>S;
        string ans = "";
        for(int i=0;i<N;i++)
        {
            if(S[i]=='U')
                ans+='D';
            else if(S[i]=='D')
                ans+='U';
            else
                ans+=S[i];
                
        }
        cout<<ans<<endl;
    }
}