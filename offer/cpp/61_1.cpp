// set+遍历，满足最大值-最小值<=5且无重复即可组成顺子
// 时间O(N)=O(5)=O(1)
// 空间O(N)=O(5)=O(1)
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
  bool isStraight(vector<int> &nums) {
    int max = 0, min = 14;
    unordered_set<int> set;
    for (const auto &num : nums) {
      if (num == 0)
        continue;
      min = std::min(min, num);
      max = std::max(max, num);
      if (set.count(num)) {
        return false;
      }
      set.insert(num);
    }
    return max - min <= 5;
  }
};