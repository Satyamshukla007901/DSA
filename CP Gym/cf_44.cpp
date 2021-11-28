#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
    long long T;
    cin>>T;
    while(T-->0)
    {
        long long N;
        cin>>N;
        long long A[N+1];
        for(long long i=1;i<=N;i++)
        {
            cin>>A[i];
        }
        if(N<3)
        {
            // cout<<1<<endl;
            bool flag = false;
            for(long long i=1;i<=N;i++)
            {
                if(i!=N&&A[i]>A[i+1])
                {
                    flag = true;
                    break;
                }
            }
            if(flag)
                cout<<"NO"<<endl;
            else
                cout<<"YES"<<endl;
        }
        else
        {
            bool flag = false;
            for(long long i=1;i<=N-2;i++)
            {
                if(A[i]>A[i+2]&&((A[i]+A[i+2])>A[i+1]))
                {
                    long long temp = A[i];
                    A[i] = A[i+2];
                    A[i+2] = temp;
                }
            }
            for(long long i=1;i<=N-2;i++)
            {
                if(A[i]>A[i+2]&&((A[i]+A[i+2])>A[i+1]))
                {
                    long long temp = A[i];
                    A[i] = A[i+2];
                    A[i+2] = temp;
                }
            }

            int count=0;
            for(long long i=1;i<=N;i++)
            {
                if(i!=N&&A[i]<A[i+1])
                {
                    count++;
                    break;
                }
            }
            if(count!=N-1)
                flag = false;
            if(flag)
                cout<<"NO"<<endl;
            else
                cout<<"YES"<<endl;
        }
    }
    return 0;
}