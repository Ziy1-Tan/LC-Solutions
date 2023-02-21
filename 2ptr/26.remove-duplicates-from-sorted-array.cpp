#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  int removeDuplicates(vector<int> &nums) {
    int slow = 0;
    for (int fast = 0; fast < nums.size(); fast++) {
      if (nums[fast] != nums[slow]) {
        nums[++slow] = nums[fast];
      }
    }
    return slow + 1;
  }
};

int main(int argc, const char *argv[]) {
  vector<int> nums{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  assert((new Solution)->removeDuplicates(nums) == 5);
  return 0;
}
