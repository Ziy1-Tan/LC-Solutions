#include <iostream>
#include <tuple>
#include <vector>
using namespace std;
class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int maxSum = nums[0];
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    int ans = dp[0];
    for (int i = 1; i < nums.size(); i++) {
      dp[i] = max(dp[i - 1] + nums[i], nums[i]);
      ans = max(ans, dp[i]);
    }
    return ans;
  }
};

// 求子数组
class Solution_Arr {
 public:
  tuple<int, int, int> maxSubArray(vector<int>& nums) {
    int maxSum = nums[0];
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    int ans = dp[0];
    int left = 0, right = 0;
    for (int i = 1; i < nums.size(); i++) {
      if (dp[i - 1] > 0) {
        dp[i] = dp[i - 1] + nums[i];
      } else {
        dp[i] = nums[i];
        left = i;
      }
      if (ans < dp[i]) {
        ans = dp[i];
        right = i;
      }
    }
    return {left, right, ans};
  }
};

// dp空间优化版
class Solution2 {
 public:
  int maxSubArray(vector<int>& nums) {
    int pre = nums[0], cur = 0;
    int ans = pre;
    for (int i = 1; i < nums.size(); i++) {
      if (pre > 0) {
        cur = pre + nums[i];
      } else {
        cur = nums[i];
      }
      ans = max(ans, cur);
      pre = cur;
    }
    return ans;
  }
};
int main(int argc, char const* argv[]) {
  vector<int> v{-3, 2, -1, 3, -4};
  auto [i, j, ans] = (new Solution_Arr)->maxSubArray(v);
  cout << i << " " << j << " " << ans << endl;
  return 0;
}
