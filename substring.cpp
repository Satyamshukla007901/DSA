// generate all the substrings of a string
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int32_t main()
{
    string str;
    cin>>str;
    ll l  = str.length();
    for(int i=0;i<l;i++)
    {
        string ans = "";
        for(int j=i;j<l;j++)
        {
            ans+=str[j];
            cout<<ans<<endl;
        }
        cout<<endl;
    }
    return 0;
}