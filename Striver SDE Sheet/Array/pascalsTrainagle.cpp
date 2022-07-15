//https://leetcode.com/problems/pascals-triangle/
class Solution {
public:
    vector<vector<int>> generate(int numRows)
{
        /*
    // cout<<1<<endl;
    vector<vector<int>> vp;
    if(numRows == 1)
    {
        vp.push_back({1});
        return vp;
    }
    if(numRows==2)
    {
        vp.push_back({1});
        vp.push_back({1,1});
        return vp;
    }
    vp.push_back({1});
    vp.push_back({1,1});
    
    // cout<<1<<endl;
    for(int i=2;i<numRows;i++)
    {
        vector<int> temp;
        temp.push_back(1);
        // cout<<1<<endl;
        for(int j=1;j<i;j++)
        {
            // cout<<1<<endl;
            temp.push_back(vp[i-1][j-1]+vp[i-1][j]);
        }
        temp.push_back(1);
        vp.push_back(temp);
    }
    return vp;*/
        vector<vector<int>> ans(numRows);
        ans[0] = {1};
        for(int i=1;i<numRows;i++)
        {
            vector<int> ok(i+1);
            ok[0] = 1;
            ok[i] = 1;
            for(int j=1;j<i;j++)
            {
                ok[j] = ans[i-1][j]+ans[i-1][j-1];
            }
            ans[i] = ok;
        }
        return ans;
        
}
};