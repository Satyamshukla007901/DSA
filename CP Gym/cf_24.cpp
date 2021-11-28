#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
    int n;
    cin>>n;
    int a[n],b[n];
    // int same = 0;
    // multimap<int,int> mp;
    // for(int i =0 ;i<n;i++)
    // {
    //     cin>>a[i]>>b[i];
    //     // if(i!=0)
    //     // {
    //     //     if(a[i]==a[i-1])
    //     //         same++;
    //     // }
    //     if(a[i]!=b[i]&&b[i]<=n)
    //     {
    //         mp.insert({b[i],1});
    //     }

    // }
    // cout<<n-mp.size()<<endl;
    // int ans[n+1];
    // for(int i=0;i<=n;i++)
    // {
    //     ans[i]=0;
    // }
    // for(int i=0;i<=n;i++)
    // {
    //     if(i!=n&&a[i]!=b[i]&&b[i]<=n)
    //     {
    //         ans[b[i]] = 1;
    //     }
    // }
    // int count=0;
    // for(int i=1;i<=n;i++)
    // {
    //     count+=(ans[i]==0);
    // }
    // cout<<count-same<<endl;
    //  multimap<int,int> mp;
    //  map<int,int> mp2;
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>b[i];
        // mp.insert({a[i],0});
        // mp2[a[i]]++;
    }
    int count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i]==b[j]&&j!=i)
            {
                count++;
                break;
            }
        }
    }
    cout<<n-count<<endl;
    //     // for(auto &value:mp)
    //     // cout<<value.first<<" "<<value.second<<endl;
    // for(int i=0;i<n;i++)
    // {
    //     if(mp2[a[i]]>1||a[i]!=b[i])
    //     {
    //         // auto it = mp.find(b[i]);
    //         if(mp2[a[i]]>1)
    //         {
    //             auto it = mp.find(b[i]);
    //             if(it!=mp.end()){
    //              mp.erase(it);
    //             mp.insert({b[i],1});}
    //         }
    //         else{
    //         mp.erase(b[i]);
    //         mp.insert({b[i],1});
    //         }
            
    //     }
    // }
    // // cout<<endl;
    // // for(auto &value:mp)
    // //     cout<<value.first<<" "<<value.second<<endl;
    // int count=0;
    // for(auto &value:mp)
    // {
    //     if(value.second==0)
    //         count++;
    // }
    // cout<<count<<endl;

}