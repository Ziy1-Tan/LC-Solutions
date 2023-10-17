/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res;
    for (int i = 0; i < numRows; i++) {
      vector<int> row(i + 1);
      row[0] = row[i] = 1;
      for (int j = 1; j < i; j++) {
        row[j] = res[i - 1][j] + res[i - 1][j - 1];
      }
      res.push_back(row);
    }
    return res;
  }
};
// @lc code=end
