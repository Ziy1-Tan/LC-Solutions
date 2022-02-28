// 模拟快速排序过程，基准元素比左边的元素大，比右边的元素小
// 基准元素位置i<k时，说明第K大的元素在右边，反之在左边
// i=k时，基准元素即为第K大元素
// 时间复杂度 O(N) 每次递归的范围为N N/2 N/4... 求和可得2N
// 空间复杂度 O(logN)
#include <cstdlib>
#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  int findKthLargest(vector<int> &nums, int k) {
    if (k > nums.size())
      return -1;

    return quickSelect(nums, nums.size() - k, 0, nums.size() - 1);
  }

  int quickSelect(vector<int> &nums, int target, int l, int r) {
    int i = l, j = r;
    // 随机选择一个基准元素
    int pivot = rand() % (r - l + 1) + l;
    swap(nums[l], nums[pivot]);

    // 快速排序过程
    while (i < j) {
      while (i < j && nums[j] >= nums[l])
        j--;
      while (i < j && nums[i] <= nums[l])
        i++;
      swap(nums[i], nums[j]);
    }
    swap(nums[i], nums[l]);

    if (i < target)
      return quickSelect(nums, target, i + 1, r);
    else if (i > target)
      return quickSelect(nums, target, l, i - 1);

    return nums[target];
  }
};

int main(int argc, const char *argv[]) {
  vector<int> nums{3, 2, 1, 5, 6, 4};
  cout << (new Solution())->findKthLargest(nums, 2) << endl;
  return 0;
}