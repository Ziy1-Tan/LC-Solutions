// n&(n-1)消去n最右边的1
#include <iostream>
using namespace std;

class Solution {
public:
  int hammingWeight(uint32_t n) {
    int cnt = 0;
    while (n != 0) {
      n = n & (n - 1);
      cnt++;
    }
    return cnt;
  }
};

int main(int argc, const char *argv[]) {
  cout << (new Solution())->hammingWeight(01001) << endl;
  return 0;
}