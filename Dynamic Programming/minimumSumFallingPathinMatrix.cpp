//https://leetcode.com/problems/minimum-falling-path-sum/
class Solution {
public:
    int solve(int x,int y,vector<vector<int>> &vp,vector<vector<int>> &dp)
    {
        if(x<0||y<0||x>=vp.size()||y>=vp.size())
        {
            return INT_MAX;
        }
        else if(x==0&&y<vp.size())
        {
            return vp[x][y];
        }
        if(dp[x][y]!=-1)
                return dp[x][y];
        return dp[x][y] = vp[x][y] + min(solve(x-1,y+1,vp,dp),min(solve(x-1,y,vp,dp),solve(x-1,y-1,vp,dp)));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int maxe = INT_MAX;vector<vector<int>> dp(matrix.size(),vector<int>(matrix.size(),-1));
        /*
        for(int i=0;i<matrix.size();i++)
        {
            maxe = min(maxe , solve(matrix.size()-1,i,matrix,dp));
        }
        return maxe;*/
        for(int i=0;i<matrix.size();i++)
        {
            dp[0][i] = matrix[0][i];
        }
        
        for(int i=1;i<matrix.size();i++)
        {
            for(int j = 0;j<matrix.size();j++)
            {
                int a = INT_MAX,b = INT_MAX,c = INT_MAX;
                if(i-1>=0&&j+1<matrix.size())
                        a = dp[i-1][j+1];
                if(i-1>=0)
                        b = dp[i-1][j];
                if(i-1>=0&&j-1>=0)
                        c = dp[i-1][j-1];
                dp[i][j]  = matrix[i][j] + min(a,min(b,c));
            }
        }
        for(int i=0;i<matrix.size();i++)
        {
          
            maxe = min(maxe,dp[matrix.size()-1][i]);
        }
        cout<<endl;
        return maxe;
    }
};