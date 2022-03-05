// 动态规划，dp[j]代表以s[j]结尾的字符串的最长子串
// i代表左边离j最近的与s[j]相同的字符的下标
// 状态转移：
// dp[j-1]<j-i时，说明字符串dp[j-1]在[i,j]区间内，dp[j]=dp[j-1]+1
// dp[j-1]>=j-i时，说明i在字符串dp[j-1]内，应该以i重新为界向后寻找，dp[j]=j-i
// 时间O(N)
// 空间(1) hash表只存储每个字符最后出现的位置 最多只需要存储O(128)个ASCII字符
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> dict;
    int i = -1, res = 0, tmp = 0;
    for (int j = 0; j < s.size(); j++) {
      // i的默认值为-1
      int cnt = dict.count(s[j]);
      i = cnt == 0 ? -1 : dict[s[j]];

      // 更新字符最后一次出现位置
      dict[s[j]] = j;

      // 状态转移
      if (tmp < j - i) {
        tmp += 1;
      } else {
        tmp = j - i;
      }

      // 更新最大值
      res = max(res, tmp);
    }
    return res;
  }
};

int main(int argc, const char *argv[]) {
  cout << Solution().lengthOfLongestSubstring("abcabcbb") << endl;
  return 0;
}