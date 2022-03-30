#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (nums[mid] < target)
        l = mid + 1;
      else if (nums[mid] > target)
        r = mid - 1;
      else {
        int first = mid, end = mid;
        while (first > 0 && nums[first] == nums[first - 1])
          first--;
        while (end < nums.size() - 1 && nums[end] == nums[end + 1])
          end++;
        return {first, end};
      }
    }
    return {-1, -1};
  }
};

int main(int argc, const char *argv[]) {
  vector<int> nums{5, 7, 7, 8, 8, 10};
  auto res = Solution().searchRange(nums, 8);
  cout << res[0] << " " << res[1] << endl;
  return 0;
}