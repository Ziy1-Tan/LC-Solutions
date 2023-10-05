#include <climits>
#include <iostream>
using namespace std;

class Solution {
 public:
  int reverse(int x) {
    int res = 0;
    while (x != 0) {
      int digit = x % 10;
      if (res > INT_MAX / 10 || res < INT_MIN / 10) return 0;
      res = res * 10 + digit;
      x /= 10;
    }
    return res;
  }
};

int main(int argc, const char *argv[]) {
  cout << (new Solution)->reverse(123) << endl;
  return 0;
}
