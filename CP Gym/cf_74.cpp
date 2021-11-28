#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    int T;
    cin>>T;
    while(T-->0)
    {
        int K;
        cin>>K;
        int count=0;
        int i=0;
        while(count!=K)
        {
            i++;
            if(i%3==0||i%10==3)
            {

            }
            else
                count++;
            
        }
        cout<<i<<endl;
    }
    return 0;
}