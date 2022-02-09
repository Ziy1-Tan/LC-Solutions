#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int findRepeatNumber(vector<int> &nums) {
    // 遍历数组,将对应元素放到对应下标
    int len = nums.size();
    for (int i = 0; i < len; i++) {
      int temp = -1;
      while (nums[i] != i) {
        if (nums[i] == nums[nums[i]])
          return nums[i];
        temp = nums[nums[i]];
        nums[nums[i]] = nums[i];
        nums[i] = temp;
      }
    }
    return 0;
  }
};

int main(int argc, const char *argv[]) {
  vector<int> nums{2, 3, 1, 0, 2, 5, 3};
  auto res = (new Solution())->findRepeatNumber(nums);
  cout << res << endl;
  return 0;
}