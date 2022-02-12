#include <iostream>
using namespace std;

class Solution {
public:
  int hammingWeight(uint32_t n) {
    int cnt = 0;
    for (; n != 0; n >>= 1) {
      cnt += (n & 1);
    }
    return cnt;
  }
};

int main(int argc, const char *argv[]) {
  cout << (new Solution())->hammingWeight(01001) << endl;
  return 0;
}