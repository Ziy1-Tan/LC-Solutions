// 难点：如何将两个数分开
// 全数组做异或以后的结果为x^y
// 找到x^y二进制中结果为1的值，可知x和y在该位上的值一定不相同
// 将该位上值为0的数划分为一个数组，值为1的数划分为另一个数组，可以保证相同的数划分到一个数组中，不同的数划分到不同的数组中
// 比如 x=01 y=11,根据第一位上值为0和1划分为两个数组，最后分别异或
// 时间复杂度O(N)
// 空间复杂度O(1)
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> singleNumbers(vector<int> &nums) {
    int res = 0, index = 0;
    for (int num : nums) {
      res ^= num;
    }

    // 找到第一个值为1的二进制位
    while ((res & 1) == 0) {
      res >>= 1;
      index++;
    }

    // 划分两个数组,index位为0的一组，index位为1的一组
    int res1 = 0, res2 = 0;
    for (int num : nums) {
      if (((num >> index) & 1) == 0)
        res1 ^= num;
      else
        res2 ^= num;
    }

    return vector<int>{res1, res2};
  }
};

int main(int argc, const char *argv[]) {
  vector<int> nums{1, 2, 5, 2};
  auto res = (new Solution())->singleNumbers(nums);
  cout << res[0] << " " << res[1] << endl;
  return 0;
}