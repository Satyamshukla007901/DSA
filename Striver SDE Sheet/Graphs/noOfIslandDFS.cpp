//https://takeuforward.org/data-structure/number-of-distinct-islands/
//TC->O(NxM)
//SC->O(NxM)


    void dfs(int i,int j,vector<vector<char>> &ok)
    {
        if(i<0||j<0||i>=ok.size()||j>=ok[0].size()||ok[i][j]=='0')
        {
            return;
        }
        ok[i][j]='0';
        dfs(i+1,j,ok);
        dfs(i-1,j,ok);
        // dfs(i+1,j+1,ok);
        // dfs(i-1,j+1,ok);
        // dfs(i-1,j-1,ok);
        // dfs(i+1,j-1,ok);
        dfs(i,j+1,ok);
        dfs(i,j-1,ok);
    }
    int numIslands(vector<vector<char>>& grid) {
        
        int cnt = 0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    cnt++;
                    dfs(i,j,grid);
                }
            }
        }
        return cnt;
    }