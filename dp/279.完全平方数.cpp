/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

class Solution {
 public:
  int numSquares(int n) {
    vector<int> dp(n + 1);
    for (int i = 1; i <= n; i++) {
      dp[i] = i;
      for (int j = 1; i - j * j >= 0; j++) {
        dp[i] = min(dp[i], dp[i - j * j] + 1);
      }
    }

    return dp.back();
  }
};

// int main(int argc, char const *argv[]) {
//   cout << (new Solution)->numSquares(13) << endl;
//   return 0;
// }

// @lc code=end
