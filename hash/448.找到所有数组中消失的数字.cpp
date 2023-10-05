/*
 * @lc app=leetcode.cn id=448 lang=cpp
 *
 * [448] 找到所有数组中消失的数字
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
      while (nums[i] != i + 1) {
        int j = nums[i] - 1;
        if (nums[j] == j + 1) {
          break;
        }
        swap(nums[i], nums[j]);
      }
    }
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] != i + 1) {
        res.push_back(i + 1);
      }
    }
    return res;
  }
};
// @lc code=end
