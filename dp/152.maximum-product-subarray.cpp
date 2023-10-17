#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    int n = nums.size();
    vector<int> maxDp(n);
    vector<int> minDp(n);
    maxDp[0] = nums[0];
    minDp[0] = nums[0];

    int ans = maxDp[0];
    for (int i = 1; i < n; i++) {
      if (nums[i] >= 0) {
        maxDp[i] = max(nums[i] * maxDp[i - 1], nums[i]);
        minDp[i] = min(nums[i] * minDp[i - 1], nums[i]);
        // 存在负数，还要维护一个最小值dp
      } else {
        maxDp[i] = max(nums[i] * minDp[i - 1], nums[i]);
        minDp[i] = min(nums[i] * maxDp[i - 1], nums[i]);
      }
      ans = max(ans, maxDp[i]);
    }
    return ans;
  }
};

class Solution2 {
 public:
  int maxProduct(vector<int>& nums) {
    int ans = numeric_limits<int>::min();
    int maxP = 1, minP = 1;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] >= 0) {
        maxP = max(maxP * nums[i], nums[i]);
        minP = min(minP * nums[i], nums[i]);
      } else {
        int tmp = maxP;
        maxP = max(minP * nums[i], nums[i]);
        minP = min(tmp * nums[i], nums[i]);
      }
      ans = max(ans, maxP);
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) {
  std::vector<int> nums = {-4, -3, -2};
  cout << (new Solution2)->maxProduct(nums) << endl;
  return 0;
}
