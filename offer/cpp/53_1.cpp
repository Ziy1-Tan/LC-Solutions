// 二分查找，查找到后不断缩小范围
// 时间复杂度O(logN) 当[1,2,3]时会退化为O(N)
// 空间复杂度O(1)
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  int search(vector<int> &nums, int target) {
    auto res = binSearch(nums, 0, nums.size() - 1, target);

    return res[1] - res[0] + 1;
  }

private:
  vector<int> binSearch(const vector<int> &nums, int l, int r,
                        const int target) {
    if (l > r)
      return {-1, -2};

    int mid = (l + r) / 2;

    if (nums[mid] < target)
      return binSearch(nums, mid + 1, r, target);
    else if (nums[mid] > target)
      return binSearch(nums, l, mid - 1, target);

    if (nums[l] == target && nums[r] == target) {
      return {l, r};
    }

    if (nums[l] != target)
      l++;
    if (nums[r] != target)
      r--;

    return binSearch(nums, l, r, target);
  }
};

int main(int argc, const char *argv[]) {
  vector<int> nums{5, 7, 7, 8, 8, 10};
  cout << Solution().search(nums, 11) << endl;
  return 0;
}