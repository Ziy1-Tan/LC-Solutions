// 二分查找，若nums[mid]=mid，说明[0,mid]没有数字缺失
// 缺失数在[mid+1,r]中
// 时间复杂度O(N)
// 空间复杂读O(1)
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  int missingNumber(vector<int> &nums) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (nums[mid] == mid)
        l = mid + 1;
      else
        r = mid - 1;
    }
    // 可以直接return l;
    // return l == nums.size() ? nums.size() : nums[l] - 1;
    return l;
  }
};

int main(int argc, const char *argv[]) {
  vector<int> nums{1};
  cout << Solution().missingNumber(nums) << endl;
  return 0;
}