// 相向双指针，i从前向后找元素val，j从后向前找不为val的元素
// 找到后交换
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  int removeElement(vector<int> &nums, int val) {
    int left = 0, right = nums.size() - 1;

    while (left <= right) {
      while (left <= right && nums[left] != val)
        left++;
      while (left <= right && nums[right] == val)
        right--;

      if (left < right)
        nums[left++] = nums[right--];
    }

    return left;
  }
};

int main(int argc, const char *argv[]) {
  vector<int> nums{2, 2};
  auto res = Solution().removeElement(nums, 3);
  for (int i = 0; i < res; i++) {
    cout << nums[i] << " ";
  }
  return 0;
}