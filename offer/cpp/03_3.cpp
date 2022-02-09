#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  int findRepeatNumber(vector<int> &nums) {
    unordered_set<int> set;
    for (const auto &num : nums) {
      if (set.count(num))
        return num;
      set.insert(num);
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