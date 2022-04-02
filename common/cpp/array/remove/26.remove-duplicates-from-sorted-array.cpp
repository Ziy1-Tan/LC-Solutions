#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int slow = 0;
    for (int fast = 1; fast < nums.size(); fast++) {
      if (nums[fast] != nums[slow]) {
        // 1,2,3,4,5情况下防止多余复制
        if (fast - slow > 1) {
          nums[slow + 1] = nums[fast];
        }
        slow++;
      }
    }
    return slow + 1;
  }
};

int main(int argc, const char *argv[]) {
  vector<int> nums{1, 2, 3, 4, 5};
  auto l = Solution().removeDuplicates(nums);
  for (int i = 0; i < l; i++) {
    cout << nums[i] << " ";
  }
  return 0;
}