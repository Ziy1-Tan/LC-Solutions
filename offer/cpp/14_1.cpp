// 动态规划
// 时间复杂度O(N^2)
// 空间复杂度O(N)
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int cuttingRope(int n) {
    // dpp[i]=长度为i的绳子最大乘积
    vector<int> dp(n + 1);
    dp[2] = 1;
    // 长度为3的绳子开始
    for (int i = 3; i <= n; i++) {
      // 减去长度为j的绳子
      for (int j = 2; j < i; j++) {
        dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
        // max(j * (i - j), j * dp[i - j])
        // 表示减去长度为j的绳子后，可以继续剪也可以不剪
        // max(dp[i], max(j * (i - j), j * dp[i - j]))
        // 比较减去不同j值的绳子的大小
      }
    }
    return dp[n];
  }
};

int main(int argc, const char *argv[]) {
  cout << (new Solution())->cuttingRope(3) << endl;
  return 0;
}