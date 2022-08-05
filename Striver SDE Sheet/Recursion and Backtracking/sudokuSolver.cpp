//https://leetcode.com/problems/sudoku-solver/submissions/
class Solution {
public:
    bool isValid(vector<vector<char>>& board,int i,int j,char ch)
    {
        for(int k=0;k<9;k++)
        {
            if(board[i][k]==ch) return false;
            if(board[k][j]==ch) return false;
            if(board[3*(i/3)+k/3][3*(j/3)+k%3]==ch) return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board)
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')
                {
                    for(char ch = '1';ch<='9';ch++)
                    {
                        if(isValid(board,i,j,ch))
                        {
                            board[i][j] = ch;
                            if(solve(board))
                            {
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }
                    return false;
                    // agar koi b element nahi place krskte toh aage kya karoge krkre?
                    // isse acha retrurn false krdo
                }
                
            }
        }
        // agar is point of execution tak aaya hai yaani saari cells bhar chuki hai 
        // so we can now return true;
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};