#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
      if (map.count(target - nums[i])) {
        return {map[target - nums[i]], i};
      }
      map[nums[i]] = i;
    }
    return {-1, -1};
  }
};

int main(int argc, char const* argv[]) {
  vector<int> v{2, 7, 11, 15};
  auto ans = (new Solution)->twoSum(v, 9);
  cout << ans[0] << " " << ans[1] << endl;
  return 0;
}
