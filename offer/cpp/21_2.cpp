// 双端指针i、j分别指向数组左右两段，i从左向右搜索偶数，j从右向左搜索奇数，交换i、j指向的值
// 时间复杂度 O(N)，全为奇数或全为偶数时要遍历整个数组
// 空间复杂度 O(1)
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> exchange(vector<int> &nums) {
    if (nums.size() == 0)
      return nums;
    int i = 0, j = nums.size() - 1;
    while (i < j) {
      while (i < j && (nums[i] & 1) == 1)
        i++;
      while (i < j && (nums[j] & 1) == 0)
        j--;
      swap(nums[i], nums[j]);
    }
    return nums;
  }
};

int main(int argc, const char *argv[]) {
  vector<int> nums{1, 11, 14};
  auto res = (new Solution())->exchange(nums);
  for (auto i : res) {
    cout << i << endl;
  }
  return 0;
}