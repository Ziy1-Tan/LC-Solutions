// 利用 min^2<x、(min+1)^2>x的特性，进行二分查找
// 做了防止溢出的处理
#include <cmath>
#include <iostream>
using namespace std;

class Solution {
public:
  int mySqrt(int x) {
    if (x == 0 || x == 1)
      return x;
    int min = 1, max = x / 2;
    while (min <= max) {
      int mid = min + (max - min) / 2;
      if (mid < x / mid)
        min = mid + 1;
      else if (mid > x / mid)
        max = mid - 1;
      else
        return mid;
    }
    return max;
  }
};

int main(int argc, const char *argv[]) {
  auto res = Solution().mySqrt(8);
  cout << res << endl;
  return 0;
}