/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    // dp[天数][是否持股][卖出过多少次]
    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3)));
    // 第一天休息
    dp[0][0][0] = 0;
    // 第一天买入
    dp[0][1][0] = -prices[0];
    // 第一天不可能已经卖出
    dp[0][0][1] = numeric_limits<int>::min() / 2;
    dp[0][0][2] = numeric_limits<int>::min() / 2;
    // 第一天不可能已经卖出
    dp[0][1][1] = numeric_limits<int>::min() / 2;
    dp[0][1][2] = numeric_limits<int>::min() / 2;

    for (int i = 1; i < n; i++) {
      // 第i天未持股，卖出0、1、2次
      // 可能是今天卖的，可能是之前卖的
      dp[i][0][0] = 0;
      dp[i][0][1] = max(dp[i - 1][1][0] + prices[i], dp[i - 1][0][1]);
      dp[i][0][2] = max(dp[i - 1][1][1] + prices[i], dp[i - 1][0][2]);
      // 第i天已持股，卖出0、1、2次
      // 可能是今天买的，可能是之前买的
      dp[i][1][0] = max(dp[i - 1][0][0] - prices[i], dp[i - 1][1][0]);
      dp[i][1][1] = max(dp[i - 1][0][1] - prices[i], dp[i - 1][1][1]);
      // 卖出两次继续持股，不存在
      dp[i][1][2] = numeric_limits<int>::min() / 2;
    }

    // 买卖1次和2次
    return max({dp[n - 1][0][1], dp[n - 1][0][2], 0});
  }
};
// @lc code=end
