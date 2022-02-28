// 随机取数+验证是否是众数
// 时间复杂度：随机取数O(1)+验证众数O(N)
// 空间负责度O(1)
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int majorityElement(vector<int> &nums) {
    while (true) {
      int i = rand() % nums.size();
      int cnt = 0;
      for (int j = 0; j < nums.size(); j++) {
        if (nums[j] == nums[i])
          cnt++;
        if (cnt > nums.size() / 2) {
          return nums[i];
        }
      }
    }
    return -1;
  }
};

int main(int argc, const char *argv[]) {
  vector<int> nums{1, 2, 3, 2, 2, 2, 5, 4, 2};
  cout << (new Solution())->majorityElement(nums) << endl;
  return 0;
}