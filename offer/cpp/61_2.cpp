// 排序+遍历，数组末尾即为最大值，数组nums[j]即为最小值，j为大小王的数量
// 满足最大值-最小值<=5且无重复即可组成顺子
// 时间O(NlogN)=O(5log5)=O(1)
// 空间O(1)
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  bool isStraight(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int j = 0;

    for (int i = 0; i < 4; i++) {
      // 统计大小王数量
      if (nums[i] == 0)
        j++;
      // 判断重复
      else if (nums[i] == nums[i + 1])
        return false;
    }

    return nums[4] - nums[j] < 5;
  }
};