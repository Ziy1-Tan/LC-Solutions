// 利用 min^2<x、(min+1)^2>x的特性，进行二分查找
#include <cmath>
#include <iostream>
using namespace std;

class Solution {
public:
  int mySqrt(int x) {
    int min = 0, max = x;
    while (min <= max) {
      int mid = min + (max - min) / 2;
      if (pow(mid, 2) < x)
        min = mid + 1;
      else if (pow(mid, 2) > x)
        max = mid - 1;
      else
        return mid;
    }

    return max;
  }
};

int main(int argc, const char *argv[]) {
  auto res = Solution().mySqrt(10);
  cout << res << endl;
  return 0;
}