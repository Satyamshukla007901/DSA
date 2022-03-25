//https://leetcode.com/problems/two-city-scheduling/submissions/
class Solution {
public:
    //if we want to sort according to the diffwernces then do the sorting by differebce
    static bool cmp(vector<int> a,vector<int> b)
    {
        return (a[0]-a[1])<(b[0]-b[1]);
    }
    int twoCitySchedCost(vector<vector<int>>& vp) {
        int sum = 0;
        sort(vp.begin(),vp.end(),cmp);
        int mid = vp.size()/2;
        for(int i=0;i<mid;i++)
                sum+=vp[i][0];
        for(int i=mid;i<vp.size();i++)
                sum+=vp[i][1];
        return sum;
        
    }
};