// dfs,边界条件：碰到数组边界或到达右下角
// 时间复杂度O(MN)
// 空间复杂度O(1)
// 超时...
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  int maxValue(vector<vector<int>> &grid) {
    if (grid.size() == 0) {
      return -1;
    }

    dfs(0, 0, grid, grid.size() - 1, grid[0].size() - 1);

    return res;
  }

private:
  int res = 0;
  int cur = 0;
  void dfs(int i, int j, const vector<vector<int>> &grid, const int m,
           const int n) {
    if (i == m && j == n) {
      res = max(cur + grid[i][j], res);
      return;
    }

    if (i > m || j > n) {
      return;
    }

    cur += grid[i][j];
    //向右向下走
    dfs(i, j + 1, grid, m, n);
    dfs(i + 1, j, grid, m, n);
    cur -= grid[i][j];
  }
};

int main(int argc, const char *argv[]) {
  vector<vector<int>> grid{{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
  cout << Solution().maxValue(grid) << endl;
  return 0;
}