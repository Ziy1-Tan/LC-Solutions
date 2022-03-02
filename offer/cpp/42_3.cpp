// 动态规划
// 状态定义：
// dp[i]以nums[i]结尾的连续子数组最大和(包含nums[i]是为了满足连续子数组)
// 转移方程： dp[i]=max(nums[i],dp[i-1]+nums[i])
// dp[i-1]<=0时，说明以dp[i-1]对dp[i] 产生负贡献，所以nums[i]单独成一段
// 空间复杂度降低，由于dp[i]只与dp[i-1]有关，所以只需要用两个变量分别保存即可
// 初始化dp[0]=nums[0] pre=0
// 时间复杂度O(N)
// 空间复杂度O(1)
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int res = nums[0], pre = 0;
    for (int i = 0; i < nums.size(); i++) {
      pre = max(pre + nums[i], nums[i]);
      res = max(pre, res);
    }
    return res;
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