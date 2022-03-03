// 动态规划 dp[i][j]代表从(0,0)走到i x j数组右下角的最大值
// 转移方程： dp[i][j]= max{dp[i-1][j],dp[i][j-1]}+grid[i][j]
// 初始值： dp[0][j] dp[i][0] 只有一种走法，直接求和
// 时间复杂度O(MN)
// 空间复杂度O(1) 利用原数组
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
    int m = grid.size(), n = grid[0].size();
    for (int i = 1; i < m; i++) {
      grid[i][0] += grid[i - 1][0];
    }

    for (int j = 1; j < n; j++) {
      grid[0][j] += grid[0][j - 1];
    }

    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        grid[i][j] = max(grid[i - 1][j], grid[i][j - 1]) + grid[i][j];
      }
    }

    return grid[m - 1][n - 1];
  }
};

int main(int argc, const char *argv[]) {
  vector<vector<int>> grid{{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
  cout << Solution().maxValue(grid) << endl;
  return 0;
}