// 1.找到n对应的数的数位和该数位的最小值
// 2.确定n对应哪个数字
// 3.确定n对应这个数字的第几位
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
  int findNthDigit(int n) {
    int digit = 1;
    long long start = 1;
    long long count = 9;
    while (n > count) {
      n -= count;
      start *= 10;
      digit += 1;
      count = 9 * digit * start;
    }
    int num = start + (n - 1) / digit;

    return to_string(num)[(n - 1) % digit] - '0';
  }
};

int main(int argc, const char *argv[]) {
  cout << (new Solution())->findNthDigit(20) << endl;
  return 0;
}