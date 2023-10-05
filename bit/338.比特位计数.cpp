/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> countBits(int n) {
    vector<int> res(n + 1);
    for (int i = 0; i <= n; i++) {
      int num = i;
      while (num) {
        num = num & (num - 1);
        res[i]++;
      }
    }
    return res;
  }
};

class Solution2 {
 public:
  vector<int> countBits(int n) {
    vector<int> res(n + 1);
    res[0] = 0;
    for (int i = 0; i <= n; i++) {
      if (i % 2 == 1) {
        res[i] = res[i - 1] + 1;
      } else {
        res[i] = res[i / 2];
      }
    }
    return res;
  }
};
// @lc code=end
