#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int findRepeatNumber(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 1; i++) {
      if (nums[i] == nums[i + 1])
        return nums[i];
    }
    return 0;
  }
};

int main(int argc, const char *argv[]) {
  vector<int> nums{2, 3, 1, 0, 2, 5, 3};
  auto res = (new Solution())->findRepeatNumber(nums);
  cout << res << endl;
  return 0;
}