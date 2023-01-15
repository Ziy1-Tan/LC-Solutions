#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    void solveSudoku(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                    continue;
                int num = board[i][j] - '1';
                int k = (i / 3) * 3 + j / 3;
                row[i][num] = col[j][num] = used[k][num] = 1;
            }

        dfs(board, 0);
    }

private:
    vector<vector<int>> row{9, vector<int>(9, 0)};
    vector<vector<int>> col{9, vector<int>(9, 0)};
    vector<vector<int>> used{9, vector<int>(9, 0)};
    bool dfs(vector<vector<char>> &board, int n)
    {
        if (n == 81)
            return true;

        int i = n / 9, j = n % 9;
        if (board[i][j] != '.')
            return dfs(board, n + 1);

        int k = (i / 3) * 3 + j / 3;
        for (int num = 0; num < 9; num++)
        {
            if (row[i][num] || col[j][num] || used[k][num])
                continue;

            row[i][num] = col[j][num] = used[k][num] = 1;
            board[i][j] = (char)('1' + num);
            if (dfs(board, n + 1))
                return true;
            board[i][j] = '.';
            row[i][num] = col[j][num] = used[k][num] = 0;
        }
        return false;
    }
};
