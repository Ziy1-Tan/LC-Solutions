/*
 * @lc app=leetcode.cn id=523 lang=cpp
 *
 * [523] 连续的子数组和
 */

// @lc code=start
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  bool checkSubarraySum(vector<int>& nums, int k) {
    if (nums.size() < 2) {
      return false;
    }
    // 余数相等的前缀和必定存在子数组和为k的倍数
    // 前缀和除以k的余数=>对应的下标
    unordered_map<int, int> map{{0, -1}};
    int rem = 0;
    for (int i = 0; i < nums.size(); i++) {
      rem = (rem + nums[i]) % k;
      if (map.count(rem)) {
        int pos = map[rem];
        if (i - pos >= 2) {
          return true;
        }
      } else {
        map[rem] = i;
      }
    }

    return false;
  }
};
// @lc code=end
