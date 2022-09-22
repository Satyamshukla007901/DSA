//https://www.interviewbit.com/problems/allocate-books/
bool cmp(int mid,vector<int> &A,int B)
{
    int idx = 0;
    for(int i=1;i<=B;i++)
    {
        int a = 0;
        while(idx<A.size() and a+A[idx]<=mid)
        {
            a = a+A[idx];
            idx++;
        }
        if(a==0) break;
    }
    return idx==A.size();
}
int Solution::books(vector<int> &A, int B) {
    if(B>A.size()) return -1;
    int a = 1;
    int b = 0;
    for(auto &value:A) b+=value;
    int ans = -1;
    while(a<=b)
    {
        int mid = a+(b-a)/2;
        if(cmp(mid,A,B))
        {
            ans = mid;
            b = mid-1;
        }
        else
            a = mid+1;
    }
    return ans;
}