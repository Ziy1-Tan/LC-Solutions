/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isMatch(string s, string p) {
    int n = s.size(), m = p.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    dp[0][0] = true;
    // "" "b*" => true
    for (int j = 2; j <= m; j++) {
      dp[0][j] = dp[0][j - 2] && p[j - 1] == '*';
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (p[j - 1] == '*') {
          // *匹配0、1和多次
          if (dp[i][j - 2])
            dp[i][j] = true;
          else if (dp[i - 1][j] && s[i - 1] == p[j - 2])
            dp[i][j] = true;
          else if (dp[i - 1][j] && p[j - 2] == '.')
            dp[i][j] = true;
        } else {
          // 匹配1次
          if (dp[i - 1][j - 1] && s[i - 1] == p[j - 1])
            dp[i][j] = true;
          else if (dp[i - 1][j - 1] && p[j - 1] == '.')
            dp[i][j] = true;
        }
      }
    }

    return dp.back().back();
  }
};
// @lc code=end
