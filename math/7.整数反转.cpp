/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
#include <limits>
using namespace std;

class Solution {
 public:
  int reverse(int x) {
    int res = 0;
    while (x) {
      int digit = x % 10;
      if (res > numeric_limits<int>::max() / 10 ||
          res < numeric_limits<int>::min() / 10) {
        return 0;
      }
      res = res * 10 + digit;
      x /= 10;
    }
    return res;
  }
};
// @lc code=end
