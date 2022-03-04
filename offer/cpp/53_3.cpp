// 两次二分查找，第一次二分查找找到target序列右边界，第二次二分查找找到target序列左边界
// 找到target时，target的右边界在[mid+1,j],左边界在[i,mid-1]
// 时间复杂度O(logN)
// 空间复杂度O(1)
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  int search(vector<int> &nums, int target) {
    int left, right;
    int i = 0, j = nums.size() - 1;
    // 寻找target的右边界
    while (i <= j) {
      int mid = i + (j - i) / 2;
      if (nums[mid] <= target)
        i = mid + 1;
      else
        j = mid - 1;
    }
    // target不存在 直接返回
    if (j >= 0 && nums[j] != target)
      return 0;
    right = i;
    i = 0;
    // 寻找target的左边界
    while (i <= j) {
      int mid = i + (j - i) / 2;
      if (nums[mid] < target)
        i = mid + 1;
      else
        j = mid - 1;
    }
    left = j;
    return right - left - 1;
  }
};

int main(int argc, const char *argv[]) {
  vector<int> nums{5, 7, 7, 8, 8, 10};
  cout << Solution().search(nums, 8) << endl;
  return 0;
}