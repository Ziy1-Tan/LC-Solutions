// 二分查找，查找到后不断缩小范围(非递归版本)
// 时间复杂度O(logN) 当[1,2,3,4,5,6,7] 4 时会退化为O(N)
// 空间复杂度O(1)
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  int search(vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      // l、r特别大时可以防止溢出
      int mid = l + (r - l) / 2;

      if (nums[mid] < target)
        l = mid + 1;
      else if (nums[mid] > target)
        r = mid - 1;
      else {
        if (nums[l] != target)
          l++;
        else if (nums[r] != target)
          r--;
        else
          break;
      }
    }
    return r - l + 1;
  }
};

int main(int argc, const char *argv[]) {
  vector<int> nums{5, 7, 7, 8, 8, 10};
  cout << Solution().search(nums, 8) << endl;
  return 0;
}