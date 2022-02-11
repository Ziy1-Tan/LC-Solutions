// 具体做法：尽量把绳子分成3为长度的小段，注意溢出
// 此题可以用python，自带高精度，防止溢出
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int cuttingRope(int n) {
    if (n <= 3)
      return n - 1;
    long res = 1;
    while (n > 4) {
      res = res * 3 % 1000000007;
      n -= 3;
    }
    return res * n % 1000000007;
  }
};

int main(int argc, const char *argv[]) {
  cout << (new Solution())->cuttingRope(1000) << endl;
  return 0;
}