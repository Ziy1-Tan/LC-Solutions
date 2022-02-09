#include <iostream>
using namespace std;

class Solution {
public:
  int numWays(int n) {
    if (n == 0)
      return 1;
    if (n < 3)
      return n;
    int p = 1, q = 2, sum;
    for (int i = 2; i < n; i++) {
      sum = (p + q) % (int)(1e9 + 7);
      p = q;
      q = sum;
    }
    return sum;
  }
};

int main(int argc, const char *argv[]) {
  auto res = (new Solution())->numWays(4);
  cout << res << endl;
  return 0;
}