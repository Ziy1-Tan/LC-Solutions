// 三指针，已有的丑数序列上的每个数x，对每个x求2x、3x、5x,得到的最小的数就是下一个丑数
// 问题：对每个x求2x、3x、5x会产生大量重复无序
// 去重方法：用a、b、c三个指针来表示有前面有a-1个数乘过2了
// 某个状态下已知a、b、c可知第a个数还没有乘过2,第b个数还没有乘过3、第c个数还没有乘过5
// 则下个丑数为2a、3b、5c中最小的那个
// 要记录dp[i]是由2a、3b还是5c产生，只需要对比dp[i]与哪一个相等即可，例如dp[i]=2a,则下一个丑数要从2(a+1)产生所以a++
// 时间复杂度O(N)
// 空间复杂度O(N)
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  int nthUglyNumber(int n) {
    int a = 0, b = 0, c = 0;
    vector<int> dp(n, 1);
    for (int i = 1; i < n; i++) {
      int n1 = 2 * dp[a], n3 = 3 * dp[b], n5 = 5 * dp[c];
      dp[i] = min(min(n1, n3), n5);
      if (dp[i] == n1)
        a++;
      if (dp[i] == n3)
        b++;
      if (dp[i] == n5)
        c++;
    }
    return dp[n - 1];
  }
};

int main(int argc, const char *argv[]) {
  // 1, 2, 3, 4, 5, 6, 8, 9, 10, 12
  auto num = Solution().nthUglyNumber(11);
  cout << num << endl;
  return 0;
}