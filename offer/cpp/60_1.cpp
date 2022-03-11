// 动态规划
// 状态定义：dp[i][j]代表i个骰子出现值为j的概率
// 转移方程：dp[i][j]= dp[i-1][j-k] * 1/6 其中k的范围是1-6
// i个骰子出现j，等于i-1个骰子出现j-k * 1个骰子出现k
// 因为1个骰子每个值的概率都是1/6 所以都乘以1/6
// 初始值dp[1][j]=[1/6, ..., 1/6]
// 时间复杂度O(N^2) 每个骰子的情况都需要统计，一共n个骰子
// 每个骰子都有5n+1个值
// 空间复杂度O(N^2)
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  vector<double> dicesProbability(int n) {
    // dp[i][j]表示i个骰子出现值为j的概率
    vector<vector<double>> dp(n + 1, vector<double>(6 * n + 1));

    // 初始化
    for (int j = 1; j <= 6; j++) {
      dp[1][j] = 1.0 / 6.0;
    }

    for (int i = 2; i <= n; i++) {
      for (int j = i; j <= 6 * i; j++) {
        for (int k = 1; k <= 6; k++) {
          if (j - k > 0) {
            dp[i][j] += dp[i - 1][j - k] / 6.0;
          } else {
            break;
          }
        }
      }
    }

    // n个骰子最大值6n,最小值n,一共6n-n+1个值
    vector<double> res(5 * n + 1);
    for (int i = 0; i < res.size(); i++) {
      res[i] = dp[n][n + i];
    }

    return res;
  }
};

int main(int argc, const char *argv[]) {
  auto res = Solution().dicesProbability(2);
  for (const auto prob : res) {
    printf("%lf ", prob);
  }
  return 0;
}