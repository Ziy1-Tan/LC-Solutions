/*
 * @lc app=leetcode.cn id=718 lang=cpp
 *
 * [718] 最长重复子数组
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int findLength(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.empty() || nums2.empty()) {
      return 0;
    }

    int n = nums1.size(), m = nums2.size();
    vector<vector<int>> dp(n, vector<int>(m));
    int maxLen = 0;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (nums1[i] == nums2[j]) {
          if (i == 0 || j == 0) {
            dp[i][j] = 1;
          } else {
            dp[i][j] = dp[i - 1][j - 1] + 1;
          }
          maxLen = max(maxLen, dp[i][j]);
        }
      }
    }
    return maxLen;
  }
};
// @lc code=end
