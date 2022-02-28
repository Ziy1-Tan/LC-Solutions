// 时间复杂度O(n)
// 空间复杂度O(1)
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int majorityElement(vector<int> &nums) {
    unordered_map<int, int> dict;
    int size = nums.size() / 2;
    for (const auto num : nums) {
      dict[num]++;
      if (dict[num] >= size)
        return num;
    }

    return -1;
  }
};

int main(int argc, const char *argv[]) {
  vector<int> nums{3, 3, 3, 2, 3, 3, 5, 4, 2};
  cout << (new Solution())->majorityElement(nums) << endl;
  return 0;
}