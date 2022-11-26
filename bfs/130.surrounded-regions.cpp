#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution
{
public:
  vector<vector<int>> visited;
  void solve(vector<vector<char>> &board)
  {
    int r = board.size();
    if (r == 0)
    {
      return;
    }

    int c = board[0].size();
    for (int i = 0; i < r; i++)
    {
      dfs(board, i, 0);
      dfs(board, i, c - 1);
    }

    for (int i = 0; i < c; i++)
    {
      dfs(board, 0, i);
      dfs(board, r - 1, i);
    }

    for (int i = 0; i < r; i++)
    {
      for (int j = 0; j < c; j++)
      {
        if (board[i][j] == 'O')
          board[i][j] = 'X';
        if (board[i][j] == 'B')
          board[i][j] = 'O';
      }
    }
  }

private:
  void dfs(vector<vector<char>> &board, const int r, const int c)
  {
    queue<pair<int, int>> q;
    q.push({r, c});
    while (!q.empty())
    {
      auto p = q.front();
      q.pop();
      int i = p.first;
      int j = p.second;
      if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
      {
        continue;
      }

      if (board[i][j] != 'O')
      {
        continue;
      }

      board[i][j] = 'B';
      q.push({i - 1, j});
      q.push({i + 1, j});
      q.push({i, j - 1});
      q.push({i, j + 1});
    }
  }
};

int main()
{
  Solution s;
  vector<vector<char>> board{
      {'X', 'O', 'X', 'O', 'X', 'O'},
      {'O', 'X', 'O', 'X', 'O', 'X'},
      {'X', 'O', 'X', 'O', 'X', 'O'},
      {'O', 'X', 'O', 'X', 'O', 'X'},
  };
  s.solve(board);

  for (const auto row : board)
  {
    for (const auto i : row)
    {
      cout << i;
    }
    cout << '\n';
  }
  return 0;
}
