// 快慢指针优化，快指针负责寻找第一个奇数，慢指针指向第一个偶数
// 时间复杂度 O(N)，数组存在较多奇数时，会比首尾指针多进行交换
// 空间复杂度 O(1)
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> exchange(vector<int> &nums) {
    int i = 0, j = 0;
    while (j < nums.size()) {
      if ((nums[j] & 1) == 1)
        swap(nums[i++], nums[j]);
      j++;
    }
    return nums;
  }
};

int main(int argc, const char *argv[]) {
  vector<int> nums{5, 12, 14, 1, 3, 4};
  auto res = (new Solution())->exchange(nums);
  for (auto i : res) {
    cout << i << endl;
  }
  return 0;
}