// set+遍历
// 时间复杂度O(N)
// 空间复杂度O(N)
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_set<int> dict;
    for (const auto &num : nums) {
      if (!dict.count(target - num))
        dict.insert(num);
      else
        return {num, target - num};
    }
    return {};
  }
};

int main(int argc, const char *argv[]) {
  vector<int> nums{1, 2, 3, 4, 5};
  auto res = Solution().twoSum(nums, 5);
  cout << res[0] << " " << res[1] << endl;
  return 0;
}