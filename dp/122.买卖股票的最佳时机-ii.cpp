/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    if (prices.empty()) {
      return 0;
    }

    int sum = 0;
    for (int i = 1; i < prices.size(); i++) {
      if (prices[i] - prices[i - 1] > 0) {
        sum += prices[i] - prices[i - 1];
      }
    }

    return sum;
  }
};

class Solution2 {
 public:
  int maxProfit(vector<int>& prices) {
    if (prices.empty()) {
      return 0;
    }
    int n = prices.size();
    // dp[i][0] i天不持有股票，dp[i][1] i天买入股票
    // 可优化为2个变量
    vector<vector<int>> dp(n, vector(2, 0));
    dp[0][0] = 0;
    dp[0][1] = -prices[0];
    for (int i = 1; i < n; i++) {
      // 等待 or 卖出
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
      // 持股 or 买入
      dp[i][1] = max(dp[i - 1][0], dp[i - 1][0] - prices[i]);
    }
    return dp[n - 1][0];
  }
};
// @lc code=end
