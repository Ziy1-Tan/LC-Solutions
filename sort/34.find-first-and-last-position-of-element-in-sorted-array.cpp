#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    int start = binarySearch(nums, target - 1, 0, nums.size() - 1);
    int end = binarySearch(nums, target, 0, nums.size() - 1);
    if (start == end) {
      return {-1, -1};
    }
    return {start, end - 1};
  }

  int binarySearch(const vector<int>& nums, int target, int l, int r) {
    while (l <= r) {
      int mid = (l + r) / 2;
      if (nums[mid] <= target) {
        l = mid + 1;
      } else if (nums[mid] > target) {
        r = mid - 1;
      }
    }
    return l;
  }
};

int main(int argc, char const* argv[]) {
  std::vector<int> nums{5, 7, 7, 8, 8, 10};
  auto res = (new Solution)->searchRange(nums, 6);
  cout << "[" << res[0] << ", " << res[1] << "]" << endl;
  return 0;
}
