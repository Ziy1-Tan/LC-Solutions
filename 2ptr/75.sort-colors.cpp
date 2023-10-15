#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  void sortColors(vector<int>& nums) {
    // [0, zero) = 0
    // [zero, i) = 1
    // [two, n] = 2
    int n = nums.size();

    int zero = 0;
    int i = 0;
    int two = n;
    while (i < two) {
      if (nums[i] == 0) {
        swap(nums[zero], nums[i]);
        zero++;
        i++;
      } else if (nums[i] == 1) {
        i++;
      } else if (nums[i] == 2) {
        two--;
        swap(nums[i], nums[two]);
      }
    }
  }
};
