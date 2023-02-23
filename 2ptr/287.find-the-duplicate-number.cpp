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
