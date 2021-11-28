#include <bits/stdc++.h>
using namespace std;


int32_t main()
{
    int T;
    cin>>T;
    while(T-->0)
    {
        string S;
        cin>>S;
        if(S.length()%2!=0)
            cout<<"NO"<<endl;
        else
        {
            int A=0;
            int B=0;
            int C=0;
            for(auto &value:S)
            {
                if(value=='A')
                    A++;
                else if(value=='B')
                    B++;
                else
                    C++;
            }
            if(A+C==B)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
    }
    return 0;
}