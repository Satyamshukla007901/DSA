#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
    long long N;
    cin>>N;
    vector<long long> v;
    for(int i=0;i<N;i++)
    {
        long long x;
        cin>>x;
        v.push_back(x);
    }
    vector<long long> b=v;
    sort(b.begin(),b.end());
    long long first=1,second=1;
    for(int i=0;i<v.size();i++)
    {
        if(v[i]!=b[i])
        {
            first = i+1;
            break;
        }
    }
    for(int i=v.size()-1;i>=0;i--)
    {
        if(v[i]!=b[i])
        {
            second = i+1;
            break;
        }
    }
    // cout<<first<<" "<<second<<endl;
    reverse(&v[first-1],&v[second-1]+1);
    // for(auto value:v)
    //     cout<<value<<" ";
    // cout<<endl;
    bool ans = true;
    for(int i=0;i<v.size();i++)
    {
        if(v[i]!=b[i])
        {
            cout<<"no"<<endl;
            ans = false;
            break;
        }
    }
    if(ans)
    {
        cout<<"yes"<<endl;
        cout<<first<<" "<<second<<endl;
    }
}