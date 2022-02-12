// 快速幂写法 x^n=(x^2)^(n/2)
// 每次利用x=x^2来减少计算幂
// n为偶数 res=res*(x^2)^(n/2), x=x^2
// n为奇数 res=(res*x)*(x^2)^(n/2), x=x^2
// 时间复杂度O(log_2 N)
// 空间复杂度O(1)
#include <iostream>
using namespace std;
class Solution {
public:
  double myPow(double x, int n) {
    if (x == 0)
      return 0;
    long b = n;
    if (n < 0) {
      b = -b;
      x = 1 / x;
    }
    double res = 1.0;
    while (b > 0) {
      //判断当前幂的奇偶性
      if ((b & 1) == 1)
        res *= x;
      x *= x;
      b >>= 1;
    }
    return res;
  }
};

int main(int argc, const char *argv[]) {
  cout << (new Solution())->myPow(22.14659, -2) << endl;
  return 0;
}