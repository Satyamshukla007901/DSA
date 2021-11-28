#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    int T;
    cin>>T;
    while(T-->0)
    {
        int A,B;
        cin>>A>>B;
        if(A>0 && B>0)
            cout<<"Solution"<<endl;
        else if(B==0)
            cout<<"Solid"<<endl;
        else
            cout<<"Liquid"<<endl;
    }
    return 0;
}