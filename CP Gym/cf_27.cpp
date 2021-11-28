#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
    int T;
    cin>>T;
    while(T-->0)
    {
        int N,M,X;
        cin>>N>>M>>X;
        map<int,int, greater <int>> A;
        vector<int> vp;
        for(int i=0;i<N;i++)
        {
            // cin>>A[i];
            int x;
            cin>>x;
            if(x>=M)
                vp.push_back(i+1);
            else
                A.insert({x,i+1});
            
        }
        // for(auto &value:A)
        //     cout<<value.first<<" "<<value.second<<endl;;
        if(vp.size()<X)
        {
            // auto it = A.end();
            // --it;
            // int count=0;
            // for(auto i = it;i!=A.begin();i--)
            // {
            //     if(count==(X-vp.size()))
            //         break;
            //     vp.push_back((*i).second);
            //     count++;
            // }
            int count=vp.size();
            for(auto &value:A)
            {
                if(count==(X))
                    break;
                
                vp.push_back(value.second);
                count++;
            }

        }
        cout<<vp.size()<<" ";
        sort(vp.begin(),vp.end());
        for(auto &value:vp)
            cout<<value<<" ";
        cout<<endl;

    }
}