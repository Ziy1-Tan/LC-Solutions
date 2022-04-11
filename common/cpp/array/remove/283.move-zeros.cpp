#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  void moveZeroes(vector<int> &nums) {
    int slow = 0;
    for (int fast = 0; fast < nums.size(); fast++) {
      if (nums[fast] != 0) {
        nums[slow++] = nums[fast];
      }
    }
    while (slow < nums.size())
      nums[slow++] = 0;
  }
};

int main(int argc, const char *argv[]) {
  vector<int> nums{0, 0, 1};
  Solution().moveZeroes(nums);
  for (int num : nums) {
    cout << num << " ";
  }
  return 0;
}