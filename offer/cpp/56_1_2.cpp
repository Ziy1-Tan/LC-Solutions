// 统计每一二进制位上所有数的值，若某一数出现三次，则该数每一位上的和一定可以被3整除
// 根据上述规律，将所有数每一位上的二进制值分别进行求和后求余，求余的值即为结果该位上的值
// 时间复杂度O(N)
// 空间复杂度O(1)
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  int singleNumbers(vector<int> &nums) {
    vector<int> sum(32, 0);
    // 统计每一位上所有数的值
    for (int num : nums) {
      for (int i = 0; i < 32; i++) {
        sum[i] += num & 1;
        num >>= 1;
      }
    }
    // 对每一位上的值进行求余
    int res = 0;
    for (int i = 0; i < 32; i++) {
      res |= (sum[i] % 3) << i;
    }

    return res;
  }
};

int main(int argc, const char *argv[]) {
  vector<int> nums{1, 1, 1, 7, 2, 2, 2, 5, 5, 5};
  auto res = (new Solution())->singleNumbers(nums);
  cout << res << endl;
  return 0;
}