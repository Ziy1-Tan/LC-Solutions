// 动态规划，F(N)的值只和F(N-1)和F(N-2)有关,只需用3个变量交替保存F(N)、F(N-1)、F(N-2)的值
// 时间复杂度O(N)
// 空间复杂度O(1)
#include <iostream>
using namespace std;

class Solution {
public:
  int fib(int n) {
    const int MOD = 1000000007;
    if (n < 2)
      return n;
    int a = 0, b = 1, sum;
    while (n-- > 1) {
      sum = (a + b) % MOD;
      a = b;
      b = sum;
    }
    return sum;
  }
};