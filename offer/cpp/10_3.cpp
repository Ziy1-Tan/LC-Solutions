// 记忆化存储，递归过程中用数组保存计算过的值
// 时间复杂度O(N)
// 空间复杂度O(1)，题目限制n小于等于100,数组大小固定
#include <iostream>
using namespace std;

class Solution {
public:
  int cache[101];
  int fib(int n) {
    if (n < 2)
      return n;
    if (cache[n] != 0)
      return cache[n];
    cache[n] = (fib(n - 1) + fib(n - 2)) % (int)(1e9 + 7);
    return cache[n];
  }
};