// https://www.interviewbit.com/problems/maximum-sum-combinations/
struct cmp
{
    bool operator()(pair<int,pair<int,int>> &p1,pair<int,pair<int,int>> &p2)
    {
        return p1.first<p2.first;
    }  
};
vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,cmp> pq;
    vector<int> ans;
    set<pair<int,int>> s;
    s.insert({A.size()-1,B.size()-1});
    pq.push({A[A.size()-1]+B[B.size()-1],{A.size()-1,B.size()-1}});
    while(ans.size()!=C)
    {
        int val = pq.top().first;
        int i = pq.top().second.first;
        int j = pq.top().second.second;
        pq.pop();
        ans.push_back(val);
        if(i>0 and s.find({i-1,j})==s.end())
        {
            pq.push({A[i-1]+B[j],{i-1,j}});
            s.insert({i-1,j});
        }
        if(j>0 and s.find({i,j-1})==s.end())
        {
            pq.push({A[i]+B[j-1],{i,j-1}});
            s.insert({i,j-1});
        }
    }
    return ans;
}
