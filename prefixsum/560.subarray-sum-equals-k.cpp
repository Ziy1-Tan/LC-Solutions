#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    int cnt = 0, pre = 0;
    unordered_map<int, int> map;
    map.insert({0, 1});
    for (auto& num : nums) {
      pre += num;
      if (map.count(pre - k)) {
        cnt += map[pre - k];
      }
      map[pre]++;
    }

    return cnt;
  }
};

int main(int argc, char const* argv[]) {
  std::vector<int> nums{1, 1, 1};
  cout << (new Solution)->subarraySum(nums, 2) << endl;
  return 0;
}
