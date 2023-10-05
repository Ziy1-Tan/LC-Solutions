#include <vector>
using namespace std;
class Solution {
 public:
  int findDuplicate(vector<int>& nums) {
    int slow = 0, fast = 0;
    slow = nums[slow];
    fast = nums[nums[fast]];
    while (slow != fast) {
      slow = nums[slow];
      fast = nums[nums[fast]];
    }

    int tmp = 0;
    while (tmp != slow) {
      tmp = nums[tmp];
      slow = nums[slow];
    }
    return tmp;
  }
};

class Solution2 {
 public:
  int findDuplicate(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
      while (nums[i] != i + 1) {
        int j = nums[i] - 1;
        if (nums[j] == j + 1) {
          return nums[j];
        }
        swap(nums[i], nums[j]);
      }
    }
    return -1;
  }
};
