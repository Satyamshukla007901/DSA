#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    int N;
    cin>>N;
    vector<string> vp;
    int a=0;
    unordered_map<string,int>mp;
    for(int i=0;i<N;i++)
    {
        string X;
        cin>>X;
        auto it = find(vp.begin(),vp.end(),X);
        if(it==vp.end())
        {
            vp.push_back(X);
            mp[X]++;
            cout<<"OK"<<endl;
        }
        else
        {
            vp.push_back(X+to_string(mp[X]));
            cout<<X+to_string(mp[X])<<endl;
            mp[X]++;
            

        }
    }

    return 0;
}