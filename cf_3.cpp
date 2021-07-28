#include <bits/stdc++.h>
using namespace std;
int32_t main()
{   
    int t;
    cin>>t;
    while(t-->0)
    {
        long long N;
        cin>>N;
        if(N%3==0)
        {
            cout<<N/3<<" "<<N/3<<endl;
        }
        else
        {
            if(N%3==2)
                cout<<(N/3)<<" "<<(N/3)+1<<endl;
            else
                cout<<(N/3)+1<<" "<<(N/3)<<endl;
        }
    }
}
