#include<bits/stdc++.h>
using namespace std;
long long A[200000]={0};
int32_t main()
{
    long long N,M;
    cin>>N>>M;long long count=0;
    for(int i=0;i<M;i++)
    {
        long long U,V;
        cin>>U>>V;
        // A[U]=V;
        //Vulnerable noble means having atleast one friend and all his/her friend should have high power
        //So we dont need the one nobles with high power
        A[min(U,V)]++;
        if(A[min(U,V)]==1)
            count++;
    }
    long long Q;
    cin>>Q;
    for(int i=0;i<Q;i++)
    {
        long long query;
        cin>>query;
        if(query==1)
        {//increading one friendship can increase the vulnerable noble so check it
            long U,V;
            cin>>U>>V;
            A[min(U,V)]++;
            if(A[min(U,V)]==1)
                count++;
        }
        else if(query==2)
        {//decreasing one frienship can decrease the vulnerable noble so check it
            long U,V;
            cin>>U>>V;
            A[min(U,V)]--;
            if(A[min(U,V)]==0)
                count--;
        }
        else
        {//Total Nobles - Vulnerable ones
            cout<<N-count<<endl;
        }
    }

}