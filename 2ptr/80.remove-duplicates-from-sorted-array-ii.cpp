#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int slow = 0;
    for (int num : nums) {
      // 数组升序，若nums[slow-2]==num
      // 则nums[slow-2]=nums[slow-1]=num已经保留了2个
      if (slow < 2 || nums[slow - 2] != num)
        nums[slow++] = num;
    }
    return slow;
  }
};
