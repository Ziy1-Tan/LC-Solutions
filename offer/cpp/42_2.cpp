// 贪心算法
// 时间复杂度O(N)
// 空间复杂度O(1)
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int max = -101, sum = 0;
    for (const auto num : nums) {
      // 小于0的抛弃
      if (sum < 0)
        sum = 0;
      sum += num;
      // 更新最大值
      max = std::max(max, sum);
    }
    return max;
  }
};

int main(int argc, const char *argv[]) {
  //   vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
  //   vector<int> nums{1};
  vector<int> nums{-2, -1};
  //   vector<int> nums{5, 4, -1, 7, 8};
  cout << (new Solution())->maxSubArray(nums) << endl;
  return 0;
}