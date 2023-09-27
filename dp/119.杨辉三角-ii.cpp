/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> getRow(int rowIndex) {
    vector<int> res(rowIndex + 1);
    vector<int> prev(rowIndex + 1);
    prev[0] = res[0] = 1;
    for (size_t i = 0; i <= rowIndex; i++) {
      res[0] = res[i] = 1;
      for (int j = 1; j < i; j++) {
        res[j] = prev[j - 1] + prev[j];
      }
      prev = res;
    }
    return res;
  }
};

class Solution2 {
 public:
  vector<int> getRow(int rowIndex) {
    vector<int> res(rowIndex + 1);
    for (size_t i = 0; i <= rowIndex; i++) {
      res[0] = res[i] = 1;
      for (int j = i; j >= 1; j--) {
        res[j] += res[j - 1];
      }
    }
    return res;
  }
};
// @lc code=end
