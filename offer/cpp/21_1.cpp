// 快慢指针，慢指针指向第一个偶数，快指针指向第一个奇数
// 时间复杂度 O(N)，情况为[2,2,2,2,1]时要遍历整个数组
// 空间复杂度 O(1)
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> exchange(vector<int> &nums) {
    int size = nums.size();
    for (int i = 0, j = 0; i < size && j < size; i++, j++) {
      if (nums[i] % 2 == 0) {
        while (j < size && nums[j] % 2 != 1)
          j++;
        if (j == size)
          break;
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
      }
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