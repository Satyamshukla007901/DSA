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
        int A[N+1];
        unordered_map<int,int> mp;
        for(int i=1;i<=N;i++)
        {
            cin>>A[i];
            mp[A[i]]++;
        }
        bool flag = false;
        for(auto &value:mp)
        {
            if(value.second>1)
            {
                flag=true;
                break;
            }
        }
        if(flag)
            cout<<"NO"<<endl;
        else    
            cout<<"YES"<<endl;
    }
}