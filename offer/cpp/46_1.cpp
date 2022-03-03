// 动态规划，dp[i]代表以下标为i结尾的数字的翻译方法数
// 转化方程: dp[i]=dp[i-1]+ dp[i-2](超过25的数无翻译)
// 初始化:dp[0]=1
// 时间复杂度O(N)
// 空间复杂度O(N) 字符串占用N大小空间
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  int translateNum(int num) {
    int res = 1, p = 1, q = 1;
    string str = to_string(num);
    for (int i = 1; i < str.size(); i++) {
      int tmp = p;
      // dp[i]=dp[i-1]+dp[i-2]  str[i-1]是避免样例506
      p = p + (stoi(str.substr(i - 1, 2)) <= 25 && str[i - 1] != '0' ? q : 0);
      // 更新
      res = p;
      q = tmp;
    }
    return res;
  }
};

int main(int argc, const char *argv[]) {
  cout << Solution().translateNum(506) << endl;
  return 0;
}