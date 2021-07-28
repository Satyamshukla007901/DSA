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
        string str = S;
        sort(str.begin(),str.end());
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(S[i]!=str[i])
                count++;
        }
        cout<<count<<endl;
    }
}