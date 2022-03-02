// 废掉，想找到最大子数组的边界，结果失败了。。。
#include <climits>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    if (nums.size() == 1)
      return nums[0];
    // 从左向右找到代价最小的
    int cost = 0;
    int l = -1;
    int min = 0;
    for (int i = 0; i < nums.size(); i++) {
      cost += nums[i];
      if (cost < min) {
        min = cost;
        l = i;
      }
    }

    // 从右向左找到代价最小的
    cost = 0, min = 0;
    int r = nums.size();
    for (int i = nums.size() - 1; i > l; i--) {
      cost += nums[i];
      if (cost < min) {
        min = cost;
        r = i;
      }
    }

    return accumulate(nums.begin() + l + 1, nums.begin() + r, 0);
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