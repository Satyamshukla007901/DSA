//https://leetcode.com/problems/flood-fill/description/

//TC>O(NxM)
//SC->O(NxM)

class Solution {
public:
    void dfs(int i,int j,vector<vector<int>> &image,int n,int c)
    {
        if(i<0||j<0) return;
        if(i>=image.size()||j>=image[0].size()) return;
        if(image[i][j]!=c)
        {
            return;
        }
        image[i][j] = n;
        dfs(i+1,j,image,n,c);
        dfs(i-1,j,image,n,c);
        dfs(i,j+1,image,n,c);
        dfs(i,j-1,image,n,c);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int a = image[sr][sc];
        if(a!=color)
        {
            dfs(sr,sc,image,color,a);
        }
        return image;
    }
};