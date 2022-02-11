// 数学推导，根据算数均值不等式，绳子等分时乘积最大。
// 设绳子长度为n,建成a段，每段长度为x，即n=ax，乘积为y=x^a
// 求y的最大值，求导可得x=e时，乘积最大，取整可得x=3时乘积最大
// 具体做法：尽量把绳子分成3为长度的小段
#include <cmath>
#include <iostream>
using namespace std;

class Solution {
public:
  int cuttingRope(int n) {
    if (n <= 3)
      return n - 1;
    int a = n / 3, b = n % 3;
    if (b == 0)
      return pow(3, a);
    // 最后一段绳子长度为1时，把1×3分成2×2
    if (b == 1)
      return pow(3, a - 1) * 4;
    return pow(3, a) * 2;
  }
};

int main(int argc, const char *argv[]) {
  cout << (new Solution())->cuttingRope(3) << endl;
  return 0;
}