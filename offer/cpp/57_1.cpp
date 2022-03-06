// 遍历+map
// 时间复杂度O(N)
// 空间复杂度O(N)
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
  unordered_map<int, int> dict;
  vector<int> twoSum(vector<int> &nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
      int left = target - nums[i];
      if (dict.count(left))
        return {nums[i], left};
      dict[nums[i]] = i;
    }
    return {-1, -1};
  }
};

int main(int argc, const char *argv[]) {
  vector<int> nums{1, 2, 3, 4, 5};
  auto res = Solution().twoSum(nums, 5);
  cout << res[0] << " " << res[1] << endl;
  return 0;
}