#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      // 大于0或连续两个相等的数跳过
      if (nums[i] > 0) break;
      if (i > 0 && nums[i] == nums[i - 1]) continue;
      int j = i + 1, k = n - 1;
      while (j < k) {
        int sum = nums[i] + nums[j] + nums[k];
        if (sum < 0)
          j++;
        else if (sum > 0)
          k--;
        else {
          res.push_back({nums[i], nums[j], nums[k]});
          while (j < k && nums[j] == nums[j + 1]) j++;
          while (j < k && nums[k] == nums[k - 1]) k--;
          j++;
          k--;
        }
      }
    }
    return res;
  }
};

int main(int argc, const char *argv[]) {
  vector<int> nums{-1, 0, 1, 2, -1, -4, 2, 3, 3};
  auto res = (new Solution)->threeSum(nums);
  auto pv = [](const auto res) {
    for (auto &i : res) cout << i << " ";
    cout << '\n';
  };
  for (auto &&i : res) {
    pv(i);
  }

  return 0;
}
