#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution
{
public:
  int numIslands(vector<vector<char>> &grid)
  {
    int cnt = 0;
    for (int i = 0; i < grid.size(); i++)
    {
      for (int j = 0; j < grid[0].size(); j++)
      {
        if (grid[i][j] == '1')
        {
          cnt++;
          dfs(grid, i, j);
        }
      }
    }
    return cnt;
  }

private:
  void dfs(vector<vector<char>> &grid, const int r, const int c)
  {
    queue<pair<int, int>> q;
    q.push({r, c});
    while (!q.empty())
    {
      auto p = q.front();
      int i = p.first;
      int j = p.second;
      q.pop();
      // 越界
      if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
      {
        continue;
      }

      // 不为岛屿
      if (grid[i][j] != '1')
      {
        continue;
      }

      grid[i][j] = '2';
      q.push({i - 1, j});
      q.push({i + 1, j});
      q.push({i, j + 1});
      q.push({i, j - 1});
    }
  }
};

int main()
{
  Solution s;
  vector<vector<char>> grid{{'1', '1', '0', '0', '0'},
                            {'1', '1', '0', '0', '0'},
                            {'0', '0', '1', '0', '0'},
                            {'0', '0', '0', '1', '1'}};
  cout << s.numIslands(grid) << endl;

  return 0;
}
