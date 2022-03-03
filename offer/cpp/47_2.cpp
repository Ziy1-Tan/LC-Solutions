// 动态规划 dp[i][j]代表从(0,0)走到i x j数组右下角的最大值
// 转移方程： dp[i][j]= max{dp[i-1][j],dp[i][j-1]}+grid[i][j]
// 初始值： dp[0][j] dp[i][0] 只有一种走法，直接求和
// 时间复杂度O(MN)
// 空间复杂度O(MN)
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

    vector<vector<int>> dp(m, vector<int>(n, 0));
    int res = 0;
    for (int i = 0; i < m; i++) {
      res += grid[i][0];
      dp[i][0] = res;
    }
    res = 0;
    for (int j = 0; j < n; j++) {
      res += grid[0][j];
      dp[0][j] = res;
    }

    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
      }
    }

    return dp[m - 1][n - 1];
  }
};

int main(int argc, const char *argv[]) {
  vector<vector<int>> grid{{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
  cout << Solution().maxValue(grid) << endl;
  return 0;
}