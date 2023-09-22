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
    for (int l = 0; l < nums.size(); l++) {
      while (nums[l] - 1 != l) {
        int r = nums[l] - 1;
        if (nums[r] - 1 == r) {
          return nums[r];
        }
        int tmp = nums[l];
        nums[l] = nums[r];
        nums[r] = tmp;
      }
    }
    return -1;
  }
};
