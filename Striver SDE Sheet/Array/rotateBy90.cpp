//https://leetcode.com/problems/rotate-image/
        int N = matrix.size();
        for(int i=0;i<N;i++) // transpose
        {
            for(int j=i;j<N;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<N;i++) //reverse
        {
            reverse(matrix[i].begin(),matrix[i].end());
        }