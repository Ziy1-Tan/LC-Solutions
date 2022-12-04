#include <iostream>
#include <queue>
#include <tuple>
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
      bfs(board, i, 0);
      bfs(board, i, c - 1);
    }

    for (int i = 0; i < c; i++)
    {
      bfs(board, 0, i);
      bfs(board, r - 1, i);
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
  void bfs(vector<vector<char>> &board, const int r, const int c)
  {
    queue<tuple<int, int>> q;
    q.push({r, c});
    while (!q.empty())
    {
      auto [i, j] = q.front();
      q.pop();
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
