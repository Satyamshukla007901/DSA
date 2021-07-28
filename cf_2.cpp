#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        long long N;
        cin>>N;
        int digit;
        int max = 0;
        while(N!=0)
        {
            digit = N%10;
            if(digit>max)
                max=digit;
            
            N/=10;
        }
        cout<<max<<endl;
    }
}