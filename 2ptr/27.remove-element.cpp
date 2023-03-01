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
  vector<int> nums{1, 1, 2, 2, 1, 5, 5};
  cout << (new Solution)->removeElement(nums, 1) << endl;
  return 0;
}
