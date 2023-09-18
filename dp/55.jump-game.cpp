#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  bool canJump(vector<int>& nums) {
    if (nums.empty()) {
      return false;
    }
    int n = nums.size();
    vector<int> dp(n);
    dp[0] = nums[0];
    for (int i = 1; i < n; i++) {
      if (i > dp[i - 1]) {
        return false;
      }
      dp[i] = max(dp[i - 1], i + nums[i]);
    }
    return true;
  }
};

class Solution2 {
 public:
  bool canJump(vector<int>& nums) {
    int k = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (i > k) {
        return false;
      }
      k = max(k, i + nums[i]);
    }
    return true;
  }
};
