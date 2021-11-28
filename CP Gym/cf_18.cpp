#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
    long long N;
    cin>>N;
    // map<long long,long long> mp;
    long long A[8]={0};
    for(int i=0;i<N;i++)
    {
        long long X;
        cin>>X;
        A[X]++;
        // mp[X]++;
    }

    long long it = N/3;
    vector<long long> v;bool flag=false;
    for(long long i=1;i<=it;i++)
    {
        if(A[1]>=1 and A[2]>=1 and A[4]>=1)
        {
            // cout<<1<<" "<<2<<" "<<4<<endl;
            v.push_back(1);
            v.push_back(2);
            v.push_back(4);
            v.push_back(0);
            A[1]--;
            A[2]--;
            A[4]--;
        }
        else if(A[1]>=1 and A[2]>=1 and A[6]>=1)
        {
            // cout<<1<<" "<<2<<" "<<6<<endl;
            v.push_back(1);
            v.push_back(2);
            v.push_back(6);
            v.push_back(0);
            A[1]--;
            A[2]--;
            A[6]--;
        }
        else if(A[1]>=1 and A[3]>=1 and A[6]>=1)
        {
            // cout<<1<<" "<<3<<" "<<6<<endl;
            v.push_back(1);
            v.push_back(3);
            v.push_back(6);
            v.push_back(0);
            A[1]--;
            A[3]--;
            A[6]--;
        }
        else
        {
            cout<<-1<<endl;
            flag=true;
            break;
        }
    }
    if(flag)
    {}
    else
    {
        for(auto &value:v)
        {
            if(value!=0)
                cout<<value<<" ";
            else
                cout<<endl;
        }
    }
    // if(mp.size()<3)
    // {
    //     cout<<-1<<endl;
    // }
    // else
    // {
    //     long long it = N/3;
    //     for(int i=1;i<=it;i++)
    //     {
    //         int itr = 3;
    //         for(auto &value:mp)
    //         {
    //             if(itr==0)
    //                 break;
    //             if(value.second!=0)
    //             {
    //                 cout<<value.first<<" ";
    //                 value.second--;
    //                 itr--;
    //             }
    //         }
    //         cout<<endl;
    //     }
    // }
    
}