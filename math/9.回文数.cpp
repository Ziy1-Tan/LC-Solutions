/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
 public:
  bool isPalindrome(int x) {
    // 负数和10的倍数(0除外)不可能为回文数
    if (x < 0 || (x % 10 == 0 && x != 0)) {
      return false;
    }

    int rev = 0;
    while (x > rev) {
      rev = rev * 10 + x % 10;
      x /= 10;
    }
    // 1221 or 12321
    return x == rev || x == rev / 10;
  }
};
// @lc code=end
