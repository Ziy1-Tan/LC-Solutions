#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        if (board.empty() || word.empty())
            return false;

        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
                if (board[i][j] == word[0] && dfs(board, i, j, word, 0))
                    return true;
        return false;
    }

private:
    bool dfs(vector<vector<char>> &board, int i, int j, string word, int idx)
    {
        if (idx >= word.size())
            return true;

        if (i < 0 || j < 0 || i >= board.size() ||
            j >= board[0].size())
            return false;

        if (board[i][j] == '&')
            return false;

        if (board[i][j] != word[idx])
            return false;

        char c = board[i][j];
        board[i][j] = '&';
        bool isExist =
            dfs(board, i + 1, j, word, idx + 1) ||
            dfs(board, i - 1, j, word, idx + 1) ||
            dfs(board, i, j + 1, word, idx + 1) ||
            dfs(board, i, j - 1, word, idx + 1);
        board[i][j] = c;
        return isExist;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<char>> board{
        {'A'}};
    auto res = (new Solution)->exist(board, "A");
    cout << res << endl;
    return 0;
}
