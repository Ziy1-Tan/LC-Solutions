/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    int l = 0;
    for (int r = 0; r < nums.size(); r++) {
      if (nums[r] != 0) {
        int tmp = nums[l];
        nums[l++] = nums[r];
        nums[r] = tmp;
      }
    }
  }
};
// @lc code=end
