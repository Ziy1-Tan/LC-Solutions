#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    int l = helper(nums, target - 1);
    int r = helper(nums, target);

    return l == r ? vector<int>{-1, -1} : vector<int>{l, r - 1};
  }

private:
  int helper(vector<int> &nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] <= target)
        left = mid + 1;
      else if (nums[mid] > target)
        right = mid - 1;
    }
    return left;
  }
};

int main(int argc, const char *argv[]) {
  vector<int> nums{5, 7, 7, 8, 8, 10};
  auto res = Solution().searchRange(nums, 5);
  cout << res[0] << " " << res[1] << endl;
  return 0;
}