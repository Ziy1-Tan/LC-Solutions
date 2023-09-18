#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    int num = nums.front();
    int cnt = 1;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] == num) {
        cnt++;
      } else if (--cnt == 0) {
        num = nums[i];
        cnt = 1;
      }
    }
    return num;
  }
};

int main(int argc, char const* argv[]) {
  std::vector<int> nums{1, 2, 2, 3, 1, 2, 2, 1, 2, 1};
  cout << (new Solution)->majorityElement(nums) << endl;
  return 0;
}
