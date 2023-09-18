#include <iostream>
using namespace std;

class Solution {
 public:
  int mySqrt(int x) {
    int l = 0, r = x, ans = -1;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if ((long long)mid * mid <= x) {
        ans = mid;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }

    return ans;
  }
};

int main(int argc, char const *argv[]) {
  cout << (new Solution)->mySqrt(190) << endl;
  return 0;
}
