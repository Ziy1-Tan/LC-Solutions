#include <vector>
using namespace std;
class Solution {
 public:
  int findDuplicate(vector<int>& nums) {
    int slow = 0, fast = 0;
    // [1,3,4,2,2] => 0->1->3->2->4->2
    // 先走一步，否则进入不了循环
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
      while (nums[i] - 1 != i) {
        int j = nums[i] - 1;
        if (nums[j] - 1 == j) {
          return nums[j];
        }
        swap(nums[i], nums[j]);
      }
    }
    return -1;
  }
};
