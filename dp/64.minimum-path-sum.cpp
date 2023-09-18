#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  int minPathSum(vector<vector<int>>& grid) {
    if (grid.size() == 0) {
      return 0;
    }

    int m = grid.size(), n = grid.front().size();
    vector<vector<int>> dp(m, vector<int>(n));
    dp[0][0] = grid[0][0];
    for (int i = 1; i < m; i++) {
      dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    for (int j = 1; j < n; j++) {
      dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
      }
    }

    return dp.back().back();
  }
};

class Solution2 {
 public:
  int minPathSum(vector<vector<int>>& grid) {
    if (grid.size() == 0) {
      return 0;
    }

    int len = grid.front().size();
    vector<int> dp(len);
    dp[0] = grid[0][0];
    for (int i = 1; i < len; i++) {
      dp[i] = dp[i - 1] + grid[0][i];
    }

    for (int i = 1; i < grid.size(); i++) {
      dp[0] = dp[0] + grid[i][0];
      for (int j = 1; j < len; j++) {
        dp[j] = min(dp[j], dp[j - 1]) + grid[i][j];
      }
    }

    return dp.back();
  }
};

int main(int argc, char const* argv[]) {
  vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 6}};
  cout << (new Solution2)->minPathSum(grid) << endl;
  return 0;
}
