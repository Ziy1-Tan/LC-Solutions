#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int res = 0;
    for (auto&& i : nums) {
      res ^= i;
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  vector<int> nums = {4, 1, 2, 1, 2};
  cout << (new Solution)->singleNumber(nums) << endl;
  return 0;
}
