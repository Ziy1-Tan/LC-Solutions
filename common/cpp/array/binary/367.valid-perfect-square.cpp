#include <iostream>
using namespace std;

class Solution {
public:
  bool isPerfectSquare(int num) {
    if (num == 0 || num == 1)
      return true;

    int min = 0, max = num;
    while (min <= max) {
      int mid = min + (max - min) / 2;
      if (mid < num / mid)
        min = mid + 1;
      else if (mid > num / mid)
        max = mid - 1;
      else
        return num % mid == 0;
    }

    return false;
  }
};

int main(int argc, const char *argv[]) {
  auto res = Solution().isPerfectSquare(9);
  cout << res << endl;
  return 0;
}