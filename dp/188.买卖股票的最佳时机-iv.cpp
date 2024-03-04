/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
 public:
  int maxProfit(int k, vector<int>& prices) {
    // dp[天数][是否持股][卖出过多少次]
    int n = prices.size();
    vector<vector<vector<int>>> dp(n,
                                   vector<vector<int>>(2, vector<int>(k + 1)));
    // 第一天休息
    dp[0][0][0] = 0;
    // 第一天买入
    dp[0][1][0] = -prices[0];
    // 第一天不可能已经卖出
    for (int i = 1; i <= k; i++) {
      dp[0][0][i] = numeric_limits<int>::min() / 2;
      dp[0][1][i] = numeric_limits<int>::min() / 2;
    }

    for (int i = 1; i < n; i++) {
      for (int j = 0; j <= k; j++) {
        if (j == 0) {
          dp[i][0][j] = 0;
        } else {
          dp[i][0][j] = max(dp[i - 1][1][j - 1] + prices[i], dp[i - 1][0][j]);
        }

        if (j == k) {
          dp[i][1][j] = numeric_limits<int>::min() / 2;
        } else {
          dp[i][1][j] = max(dp[i - 1][0][j] - prices[i], dp[i - 1][1][j]);
        }
      }
    }

    // 买卖1、2次...k次
    return max(*max_element(dp[n - 1][0].begin(), dp[n - 1][0].end()), 0);
  }
};
// @lc code=end
