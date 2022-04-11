// 利用stack模拟退格：遍历字符串的每个字符c
//  c != '#': 压入stack
//  c == '#': 栈顶元素出栈
// 最后比较两个stack中的元素是否相等
// 时间复杂度O(N)
// 空间复杂度O(N)
#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
  bool backspaceCompare(string s, string t) {
    stack<char> ss;
    for (const char c : s) 
    {
      if (c == '#' && !ss.empty())
        ss.pop();
      else if (c != '#')
        ss.push(c);
    };
    stack<char> st;
    for (const char c : t) {
      if (c == '#' && !st.empty())
        st.pop();
      else if (c != '#')
        st.push(c);
    };

    while (!ss.empty() && !st.empty()) {
      int v1 = ss.top();
      int v2 = st.top();
      if (v1 != v2)
        return false;

      ss.pop();
      st.pop();
    }

    return ss.size() == st.size();
  }
};

int main(int argc, const char *argv[]) {
  string s = "hhh###";
  string t = "";

  cout << boolalpha << Solution().backspaceCompare(s, t) << endl;
  return 0;
}