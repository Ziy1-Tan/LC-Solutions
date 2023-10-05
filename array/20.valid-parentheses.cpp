#include <iostream>
#include <stack>
using namespace std;

class Solution {
 public:
  bool isValid(string s) {
    stack<char> stack;
    for (auto &&c : s) {
      if (c == '(') {
        stack.push(')');
      } else if (c == '[') {
        stack.push(']');
      } else if (c == '{') {
        stack.push('}');
      } else {
        if (stack.empty()) {
          return false;
        }
        char tmp = stack.top();
        stack.pop();
        if (c != tmp) {
          return false;
        }
      }
    }
    return stack.empty();
  }
};

int main(int argc, char const *argv[]) {
  string s{"(){}[]"};
  cout << boolalpha;
  cout << (new Solution)->isValid(s) << endl;
  return 0;
}
