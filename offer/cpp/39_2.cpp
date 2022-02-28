// 时间复杂度O(nlogn)
// 空间复杂度O(1)
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int majorityElement(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    return nums[nums.size() / 2];
  }
};

int main(int argc, const char *argv[]) {
  vector<int> nums{1};
  cout << (new Solution())->majorityElement(nums) << endl;
  return 0;
}