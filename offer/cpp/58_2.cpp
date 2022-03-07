// 从后向前按空格切分单词并拼接
// 时间复杂度O(N)
// 空间复杂度O(N)
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  string reverseWords(string s) {
    if (s.empty())
      return s;

    string res = "";
    int i = s.size() - 1;
    while (i >= 0) {
      // 寻找第一个非空字符
      while (i >= 0 && s[i] == ' ')
        i--;
      // 记录该字符位置
      int j = i;
      // 寻找第一个空字符
      while (i >= 0 && s[i] != ' ')
        i--;
      // 拼接字符串
      if (i < j) {
        res += s.substr(i + 1, j - i);
        res += " ";
      }
    }

    res.pop_back();
    return res;
  }
};

int main(int argc, const char *argv[]) {
  auto res = Solution().reverseWords("  hello world!  ");
  cout << res << endl;
  return 0;
}