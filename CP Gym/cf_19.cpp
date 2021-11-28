#include<bits/stdc++.h>
using namespace std;
int32_t main()
{
    long long N;
    cin>>N;
    vector<long long> v;
    for(int i=0;i<N;i++)
    {
        long long X;
        cin>>X;
        v.push_back(X);
    }
    long long tfive=0,fifty=0;
    bool ans=false;
    for(int i=0;i<N;i++)
    {
        if(v[i]==25)
            tfive++;
        else if(v[i]==50)
        {
            if(tfive>=1)
            {
                tfive--;
                fifty++;
            }
            else
            {
                cout<<"NO"<<endl;
                ans=true;
                break;
            }
        }
        else
        {
            if(tfive>=1&&fifty>=1)
            {
                fifty--;
                tfive--;
            }
            else if(tfive>=3)
                tfive-=3;
            else
            {
                cout<<"NO"<<endl;
                ans=true;
                break;
            }
        }

    }
    if(ans)
    {}
    else
        cout<<"YES"<<endl;

}