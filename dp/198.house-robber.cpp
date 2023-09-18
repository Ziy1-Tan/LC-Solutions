#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  int rob(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }

    int n = nums.size();
    if (n == 1) {
      return nums.front();
    }
    vector<int> dp(nums.size());
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < nums.size(); i++) {
      dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
    }
    return dp[n - 1];
  }
};

int main(int argc, char const* argv[]) {
  vector<int> nums = {1, 2, 3, 1};
  cout << (new Solution)->rob(nums) << endl;
  return 0;
}
