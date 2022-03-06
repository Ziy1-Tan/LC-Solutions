// 双指针，利用数组升序的性质
// i,j分别指向数组的两段，nums[i]、nums[j]的和为sum
// sum>target j--
// sum<target i++
// 时间复杂度O(N)
// 空间复杂度O(1)
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
  unordered_map<int, int> dict;
  vector<int> twoSum(vector<int> &nums, int target) {
    int i = 0, j = nums.size() - 1;
    while (i < j) {
      int left = target - nums[j];
      if (left > nums[i])
        i++;
      else if (left < nums[i])
        j--;
      else
        return {nums[i], nums[j]};
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