#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int i = n - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) {
      i--;
    }

    if (i >= 0) {
      int j = n - 1;
      while (j >= 0 && nums[j] <= nums[i]) {
        j--;
      }
      swap(nums[i], nums[j]);
    }
    reverse(nums.begin() + i + 1, nums.end());
  }
};

class Solution2 {
 public:
  void nextPermutation(vector<int>& nums) {
    next_permutation(nums.begin(), nums.end());
  }
};

int main(int argc, char const* argv[]) {
  vector nums{1, 2, 3};
  (new Solution)->nextPermutation(nums);
  auto pv = [](const auto res) {
    for (auto&& i : res) cout << i << " ";
    cout << '\n';
  };
  pv(nums);
  return 0;
}
