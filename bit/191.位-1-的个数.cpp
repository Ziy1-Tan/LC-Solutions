/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */

// @lc code=start
#include <cstdlib>
using namespace std;

class Solution {
 public:
  int hammingWeight(uint32_t n) {
    uint32_t res = 0;
    while (n) {
      res += (n & 1);
      n = n >> 1;
    }

    return res;
  }
};

class Solution2 {
 public:
  int hammingWeight(uint32_t n) {
    uint32_t res = 0;
    while (n) {
      res++;
      // 最低位的1翻转
      n = n & (n - 1);
    }

    return res;
  }
};
// @lc code=end
