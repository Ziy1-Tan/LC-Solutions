// 按空格切分单词，并且倒序拼接
// 时间复杂度O(N)
// 空间复杂度O(N)
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  string reverseWords(string s) {
    vector<string> arr;

    // 按空格划分
    int i = 0;
    while (i < s.size()) {
      // 找到第一个非空格字符串
      while (s[i] == ' ')
        i++;
      // 全为空格则退出
      if (i >= s.size())
        break;
      // 找到单词的末尾
      int j = i;
      while (j < s.size() && s[j] != ' ')
        j++;

      //将单词加入
      arr.push_back(s.substr(i, j - i));

      // i从上一个单词末尾开始
      i = j;
    }

    // 倒序拼接单词
    string res = "";
    for (int i = arr.size() - 1; i >= 0; i--) {
      res = res + arr[i] + (i == 0 ? "" : " ");
    }

    return res;
  }
};

int main(int argc, const char *argv[]) {
  auto res = Solution().reverseWords("a good   example");
  cout << res << endl;
  return 0;
}