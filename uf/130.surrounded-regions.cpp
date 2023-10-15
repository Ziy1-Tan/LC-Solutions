#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  class UF
  {
  public:
    UF(int n)
    {
      for (int i = 0; i < n; i++)
      {
        parent_.push_back(i);
      }
    }

    int find(int i)
    {
      // 将i的父节点的父节点都设置为i的祖先节点
      if (parent_[i] != i)
      {
        parent_[i] = find(parent_[i]);
      }

      return parent_[i];
    }

    void unite(int i, int j)
    {
      int rooti = find(i);
      int rootj = find(j);

      if (rooti == rootj)
      {
        return;
      }

      rooti == parent_.size() - 1 ? parent_[rootj] = rooti : parent_[rooti] = rootj;
    }

  private:
    vector<int> parent_;
  };

public:
  void solve(vector<vector<char>> &board)
  {
    int r = board.size();
    if (r == 0)
    {
      return;
    }

    int c = board[0].size();
    if (c == 0)
    {
      return;
    }

    UF set(r * c + 1);

    for (int i = 0; i < r; i++)
    {
      for (int j = 0; j < c; j++)
      {
        if (board[i][j] == 'O')
        {
          // 边界的点加入标记集合，该集合代表边界O集合
          int curr = i * c + j;
          if (i == 0 || j == 0 || i == r - 1 || j == c - 1)
          {
            set.unite(curr, r * c);
          }

          if (i > 0 && board[i - 1][j] == 'O')
          {
            set.unite((i - 1) * c + j, curr);
          }

          if (j > 0 && board[i][j - 1] == 'O')
          {
            set.unite(i * c + j - 1, curr);
          }
        }
      }
    }

    for (int i = 0; i < r; i++)
    {
      for (int j = 0; j < c; j++)
      {
        if (board[i][j] == 'O' && set.find(i * c + j) != r * c)
        {
          board[i][j] = 'X';
        }
      }
    }
  }
};

int main()
{
  Solution s;
  vector<vector<char>> board{
      {'O', 'X', 'O', 'X'},
      {'X', 'O', 'X', 'X'},
      {'X', 'X', 'O', 'X'},
      {'X', 'X', 'O', 'O'},
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
