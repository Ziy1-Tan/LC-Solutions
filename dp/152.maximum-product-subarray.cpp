#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    vector<int> maxDp(nums.size());
    vector<int> minDp(nums.size());
    maxDp[0] = nums[0];
    minDp[0] = nums[0];

    int ans = maxDp[0];
    for (int i = 1; i < nums.size(); i++) {
      maxDp[i] = max({nums[i] * maxDp[i - 1], nums[i] * minDp[i - 1], nums[i]});
      minDp[i] = min({nums[i] * maxDp[i - 1], nums[i] * minDp[i - 1], nums[i]});
      ans = max(ans, maxDp[i]);
    }

    return ans;
  }
};

int main(int argc, char const* argv[]) {
  std::vector<int> nums = {-2, 2, -4};
  cout << (new Solution)->maxProduct(nums) << endl;
  return 0;
}
