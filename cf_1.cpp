#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T-->0)
    {
        long long N;
        cin>>N;
        if(N<9)
            cout<<0<<endl;
        else if(N==9)
            cout<<1<<endl;
        else
        {
            if(N%10==9)
                cout<<(N/10)+1<<endl;
            else
                cout<<(N/10)<<endl;
        }
    }
}