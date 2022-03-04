// 利用二分查找同时求target和target-1的右边界
// helper的作用：求target在数组中插入的位置，使得数组保持有序
// 时间复杂度O(logN)
// 空间复杂度O(1)
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  int search(vector<int> &nums, int target) {
    return helper(nums, target) - helper(nums, target - 1);
  }

  int helper(const vector<int> &nums, const int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (nums[mid] <= target)
        l = mid + 1;
      else
        r = mid - 1;
    }
    return l;
  }
};

int main(int argc, const char *argv[]) {
  vector<int> nums{5, 7, 7, 8, 8, 10};
  cout << Solution().search(nums, 8) << endl;
  return 0;
}