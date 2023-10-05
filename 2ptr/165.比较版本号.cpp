/*
 * @lc app=leetcode.cn id=165 lang=cpp
 *
 * [165] 比较版本号
 */

// @lc code=start
#include <iostream>
#include <string>
using namespace std;

class Solution {
 public:
  int compareVersion(string version1, string version2) {
    int len1 = version1.size(), len2 = version2.size();
    int p1 = 0, p2 = 0;
    while (p1 < len1 || p2 < len2) {
      int res1 = 0;
      while (p1 < len1 && version1[p1] != '.') {
        res1 = res1 * 10 + (version1[p1++] - '0');
      }
      p1++;
      int res2 = 0;
      while (p2 < len2 && version2[p2] != '.') {
        res2 = res2 * 10 + (version2[p2++] - '0');
      }
      p2++;

      if (res1 > res2) return 1;
      if (res1 < res2) return -1;
    }
    return 0;
  }
};

// int main(int argc, char const *argv[]) {
//   cout << (new Solution)->compareVersion("1.05", "1.1") << endl;
//   cout << (new Solution)->compareVersion("1.01.3", "1.1") << endl;
//   return 0;
// }

// @lc code=end
