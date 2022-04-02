// 快慢双指针，快指针遍历到当年前元素不等于val时，快慢指针一起移动
// 快指针等于val时，慢指针不移动
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  int removeElement(vector<int> &nums, int val) {
    int slow = 0;
    for (int fast = 0; fast < nums.size(); fast++) {
      if (nums[fast] != val) {
        nums[slow++] = nums[fast];
      }
    }
    return slow;
  }
};

int main(int argc, const char *argv[]) {
  vector<int> nums{2};
  auto res = Solution().removeElement(nums, 2);
  for (int i = 0; i < res; i++) {
    cout << nums[i] << " ";
  }
  return 0;
}