// 利用stack模拟退格：遍历字符串的每个字符c
//  c != '#': 压入stack
//  c == '#': 栈顶元素出栈
// 最后比较两个stack中的元素是否相等
// 时间复杂度O(N)
// 空间复杂度O(N)
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  bool backspaceCompare(string s, string t) {
    string resS;
    for (const char c : s) {
      if (c != '#')
        resS += c;
      else if (!resS.empty())
        resS.pop_back();
    }

    string resT;
    for (const char c : t) {
      if (c != '#')
        resT += c;
      else if (!resT.empty())
        resT.pop_back();
    }

    return !resS.compare(resT);
  }
};

int main(int argc, const char *argv[]) {
  string s = "###";
  string t = "";

  cout << boolalpha << Solution().backspaceCompare(s, t) << endl;
  return 0;
}