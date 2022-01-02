#include <bits/stdc++.h>
//print 1 to N by recursion
void printN(int N)
{
    if(N==0)
        return ;
    printN(N-1);
    cout<<N<<" ";
}