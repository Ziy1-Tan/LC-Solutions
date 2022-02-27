// 要求（1）使得原来全排列变大（2）变大的幅度尽可能小
// 解决方案（1）后面的大数与前面的小数交换（2）选择最大的小数和最小的大数交换（3）尽量在低位进行交换
// 找到第一个降序升序序列nums[i]<nums[i+1]，作为"小数"
// 在[i+1, end)中找到比nums[i]大的最小的nums[j]，作为"大数"
// 大数小数交换，把[j,end)序列翻转
// 时间复杂度O(N)
// 空间复杂度O(1)
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
  void nextPermutation(vector<int> &nums) {
    int i = nums.size() - 2;
    // 寻找小数
    while (i >= 0 && nums[i] >= nums[i + 1])
      i--;

    if (i >= 0) {
      int j = nums.size() - 1;
      while (j >= 0 && nums[i] >= nums[j])
        j--;

      swap(nums[i], nums[j]);
    }
    reverse(nums.begin() + i + 1, nums.end());
  }
};