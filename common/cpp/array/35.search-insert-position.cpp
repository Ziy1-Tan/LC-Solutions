#include <vector>
using namespace std;

class Solution {
public:
  int searchInsert(vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1;

    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (nums[mid] < target)
        l = mid + 1;
      else if (nums[mid] > target)
        r = mid - 1;
      else
        return mid;
    }

    return l;
  }
};