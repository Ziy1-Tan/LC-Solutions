// 维护一个最小值min,当当前股票prices[i]小于min时买入
// 当当前prices大于min时尝试卖出，若比历史利润res大则更新利润
// 动态规划dp[i] 前i天的最大利润
// 状态转换dp[i] = max(prices[i]-min,dp[i-1]) min表示前i-1天的最低值
// 初始化 dp[0]=0 min=prices[0]
// 时间O(N)
// 空间O(1)
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    if (prices.size() <= 1)
      return 0;

    int min = prices[0];
    int res = 0;
    for (int i = 1; i < prices.size(); i++) {
      if (min > prices[i])
        min = prices[i];
      else
        res = max(res, prices[i] - min);
    }

    return res;
  }
};

int main(int argc, const char *argv[]) {
  vector<int> prices{7, 1, 5, 3, 6, 4};
  auto res = Solution().maxProfit(prices);
  cout << res << endl;
  return 0;
}