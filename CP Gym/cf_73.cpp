#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    int T;
    cin>>T;
    while(T-->0)
    {
        int n;
        cin>>n;
        string S;
        cin>>S;
        for(int i=0;i<n;i++)
        {
            if(S[i]=='U')
                cout<<"D";
            else if(S[i]=='D')
                cout<<"U";
            else
                cout<<S[i];
        }
        cout<<endl;
    }
    return 0;
}
