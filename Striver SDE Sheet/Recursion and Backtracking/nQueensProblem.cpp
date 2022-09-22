//https://leetcode.com/problems/n-queens/submissions/
class Solution {
public:
    bool cmp(int i,int j,vector<string> &ok)
    {
        int r = i;
        int c = j;
        while(r>=0 and c>=0)
        {
            if(ok[r][c]=='Q') return false;
            r--;
            c--;
        }
        
        c = j;
        while(c>=0)
        {
            if(ok[i][c]=='Q') return false;
            c--;
        }
        
        r = i;
        c = j;
        while(r<ok.size() and c>=0)
        {
            if(ok[r][c]=='Q') return false;
            r++;
            c--;
        }
        
        return true;
    }
    void solve(int j,int n,vector<string> ok,vector<vector<string>> &ans)
    {
        if(j==n)
        {
            ans.push_back(ok);
            return;
        }
        
        for(int i=0;i<n;i++)
        {
            if(cmp(i,j,ok))
            {
                ok[i][j] = 'Q';
                solve(j+1,n,ok,ans);
                ok[i][j] = '.';
            }
        }
        
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> ok(n);
        for(int i=0;i<n;i++)
        {
            string temp = "";
            for(int j=0;j<n;j++)
            {
                temp+=".";
            }
            ok[i] = temp;
        }
        solve(0,n,ok,ans);
        return ans;
    }
};