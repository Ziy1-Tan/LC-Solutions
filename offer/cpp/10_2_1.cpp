#include <iostream>
using namespace std;

class Solution {
public:
  int cache[101];
  int numWays(int n) {
    if (n == 0)
      return 1;
    if (n < 3)
      return n;
    if (cache[n] != 0)
      return cache[n];
    cache[n] = (numWays(n - 1) + numWays(n - 2)) % (int)(1e9 + 7);
    return cache[n];
  }
};

int main(int argc, const char *argv[]) {
  auto res = (new Solution())->numWays(4);
  cout << res << endl;
  return 0;
}