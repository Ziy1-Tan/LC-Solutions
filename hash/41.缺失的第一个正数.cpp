/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  int firstMissingPositive(vector<int>& nums) {
    int len = nums.size();
    for (int i = 0; i < len; i++) {
      while (nums[i] != i + 1) {
        if (nums[i] <= 0 || nums[i] > len || nums[i] == nums[nums[i] - 1]) {
          break;
        }

        int j = nums[i] - 1;
        swap(nums[i], nums[j]);
      }
    }

    for (int i = 0; i < len; i++) {
      if (nums[i] != i + 1) {
        return i + 1;
      }
    }

    return len + 1;
  }
};

class Solution2 {
 public:
  int firstMissingPositive(vector<int>& nums) {
    unordered_set<int> set;
    for (auto&& i : nums) {
      set.insert(i);
    }

    for (int i = 1; i <= nums.size(); i++) {
      if (!set.count(i)) {
        return i;
      }
    }
    return nums.size() + 1;
  }
};
// @lc code=end
