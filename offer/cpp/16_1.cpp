// 循环相乘，超时，时间复杂度O(n)
#include <iostream>
using namespace std;
class Solution {
public:
  double myPow(double x, int n) {
    if (x == 0)
      return 0;
    int flag = 1;
    if (n < 0) {
      n = -n;
      flag = -1;
    }
    double res = 1;
    while (n > 0) {
      res *= x;
      n--;
    }
    return flag > 0 ? res : 1 / res;
  }
};

int main(int argc, const char *argv[]) {
  cout << (new Solution())->myPow(22.14659, -2) << endl;
  return 0;
}