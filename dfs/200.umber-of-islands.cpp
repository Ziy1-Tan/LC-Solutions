#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

class Solution {
 public:
  int numIslands(vector<vector<char>> &grid) {
    int cnt = 0;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] == '1') {
          cnt++;
          dfs(grid, i, j);
        }
      }
    }
    return cnt;
  }

 private:
  void dfs(vector<vector<char>> &grid, const int i, const int j) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
      return;
    }

    if (grid[i][j] != '1') {
      return;
    }

    grid[i][j] = '2';
    dfs(grid, i - 1, j);
    dfs(grid, i + 1, j);
    dfs(grid, i, j - 1);
    dfs(grid, i, j + 1);
  }
};

class Solution2 {
 public:
  int numIslands(vector<vector<char>> &grid) {
    int cnt = 0;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] == '1') {
          cnt++;
          bfs(grid, i, j);
        }
      }
    }
    return cnt;
  }

 private:
  void bfs(vector<vector<char>> &grid, const int r, const int c) {
    queue<tuple<int, int>> q;
    q.push({r, c});
    while (!q.empty()) {
      auto [i, j] = q.front();
      q.pop();
      // 越界
      if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
        continue;
      }

      // 不为岛屿
      if (grid[i][j] != '1') {
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
int main() {
  Solution s;
  vector<vector<char>> grid{{'1', '1', '0', '0', '0'},
                            {'1', '1', '0', '0', '0'},
                            {'0', '0', '1', '0', '0'},
                            {'0', '0', '0', '1', '1'}};
  cout << s.numIslands(grid) << endl;

  return 0;
}
