#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    if (prices.size() < 2) {
      return 0;
    }

    int n = prices.size();
    vector<vector<int>> dp(n, vector(2, 0));
    dp[0][0] = 0;
    dp[0][1] = -prices[0];
    for (int i = 1; i < n; i++) {
      // 继续等待 or 今天卖出
      // 继续持股 or 今天买入
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
      dp[i][1] = max(dp[i - 1][1], -prices[i]);
    }

    return dp[n - 1][0];
  }
};

class Solution2 {
 public:
  int maxProfit(vector<int>& prices) {
    if (prices.size() < 2) {
      return 0;
    }

    int n = prices.size();
    vector<int> dp(2);
    dp[1] = -prices[0];
    for (int i = 1; i < n; i++) {
      // 继续等待 or 今天卖出
      // 继续持股 or 今天买入
      dp[0] = max(dp[0], dp[1] + prices[i]);
      dp[1] = max(dp[1], -prices[i]);
    }
    return dp[0];
  }
};

class Solution3 {
 public:
  int maxProfit(vector<int>& prices) {
    if (prices.size() < 2) {
      return 0;
    }

    int n = prices.size();
    // 今天为止买入的最小值 and 今天卖出利润的最大值
    int minPrice = prices[0], res = 0;
    for (int i = 1; i < n; i++) {
      res = max(res, prices[i] - minPrice);
      minPrice = min(minPrice, prices[i]);
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  vector<int> v{7, 1, 5, 3, 6, 4};
  cout << (new Solution3)->maxProfit(v) << endl;
  return 0;
}
