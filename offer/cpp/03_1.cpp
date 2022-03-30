#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
  int findRepeatNumber(vector<int> &nums) {
    map<int, int> map;
    for (const auto &num : nums) {
      if (map.count(num)) {
        return num;
      }
      map[num] = 1;
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
