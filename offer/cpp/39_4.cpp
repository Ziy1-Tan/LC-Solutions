// 摩尔投票法，根据大于一半的数是众数的情况，记众数+1,非众数-1,最后结果一定>0
// 时间复杂度O(N)
// 空间负责度O(1)
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int majorityElement(vector<int> &nums) {
    // 当前众数和目前投票数
    int cur = nums[0], cnt = 0;
    for (const auto num : nums) {
      // 当前无人得票，新来的成为首领
      if (cnt == 0)
        cur = num;

      // 来的人和首领一伙，得1票，否则减1票
      cnt += (num == cur ? 1 : -1);
    }

    return cur;
  }
};

int main(int argc, const char *argv[]) {
  vector<int> nums{1, 2, 3, 2, 2, 2, 5, 4, 2};
  cout << (new Solution())->majorityElement(nums) << endl;
  return 0;
}