/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> productExceptSelf(vector<int> &nums) {
    int n = nums.size();
    // 索引i左侧的乘积
    vector<int> lprefix(n);
    lprefix[0] = 1;
    for (int i = 1; i < n; i++) {
      lprefix[i] = lprefix[i - 1] * nums[i - 1];
    }

    // 索引i右侧的乘积
    vector<int> rprefix(n);
    rprefix[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
      rprefix[i] = rprefix[i + 1] * nums[i + 1];
    }

    vector<int> res(n);
    for (int i = 0; i < n; i++) {
      res[i] = lprefix[i] * rprefix[i];
    }

    return res;
  }
};

class Solution2 {
 public:
  vector<int> productExceptSelf(vector<int> &nums) {
    int n = nums.size();
    vector<int> res(n, 1);
    // 分别表示前缀后缀和
    int prefix = 1, suffix = 1;
    for (int i = 0, j = n - 1; i < nums.size(); i++, j--) {
      res[i] *= prefix;
      res[j] *= suffix;
      prefix *= nums[i];
      suffix *= nums[j];
    }
    return res;
  }
};

int main(int argc, const char *argv[]) {
  vector<int> nums = {1, 2, 3, 4};
  auto res = (new Solution2)->productExceptSelf(nums);
  auto pv = [](const auto res) {
    for (auto &&i : res) cout << i << " ";
    cout << '\n';
  };
  pv(res);
  return 0;
}
// @lc code=end
