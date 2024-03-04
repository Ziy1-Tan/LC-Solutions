/*
 * @lc app=leetcode.cn id=532 lang=cpp
 *
 * [532] 数组中的 k-diff 数对
 */

// @lc code=start
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int findPairs(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int res = 0;
    int n = nums.size();
    for (int i = 0, j = 0; i < n; i++) {
      if (i != 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      while (j < n && (nums[j] < nums[i] + k || j <= i)) {
        j++;
      }
      if (j < n && nums[j] == nums[i] + k) {
        res++;
      }
    }
    return res;
  }
};
// @lc code=end
