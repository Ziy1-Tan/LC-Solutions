#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    int slow = 0;
    for (int fast = 0; fast < nums.size(); fast++) {
      if (nums[fast] != 0) {
        int tmp = nums[slow];
        nums[slow] = nums[fast];
        nums[fast] = tmp;
        slow++;
      }
    }
  }
};

int main(int argc, char const* argv[]) {
  vector<int> nums{0, 1, 0, 2, 6, 33};
  (new Solution)->moveZeroes(nums);
  auto pv = [](const auto res) {
    for (auto&& i : res) cout << i << " ";
    cout << '\n';
  };
  pv(nums);
  return 0;
}
