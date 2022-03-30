#include <iostream>
using namespace std;

class Solution {
public:
  int countDigitOne(int n) {
    int res = 0;
    for (int i = 1; i <= n; i++) {
      res += count(i);
    }
    return res;
  }

private:
  inline int count(int num) const {
    int cnt = 0;
    while (num != 0) {
      int digit = num % 10;
      if (digit == 1)
        cnt++;
      num /= 10;
    }
    return cnt;
  }
};

int main(int argc, const char *argv[]) {

  cout << Solution().countDigitOne(20) << endl;
  return 0;
}