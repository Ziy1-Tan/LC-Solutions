#include <iostream>
using namespace std;

class Solution {
public:
  int fib(int n) {
    if (n == 0)
      return 0;
    if (n == 1)
      return 1;
    int first = fib(n - 1);
    if (first > 1000000007)
      first -= 1000000007;
    int second = fib(n - 2);
    if (second > 1000000007)
      second -= 1000000007;
    return first + second;
  }
};