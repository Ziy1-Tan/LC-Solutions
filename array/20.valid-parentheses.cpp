#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
 public:
  bool isValid(string s) {
    stack<char> stack;
    for (int i = s.size() - 1; i >= 0; i--) {
      stack.push(s[i]);
    }

    while (!stack.empty()) {
      char c = stack.top();
      stack.pop();
      if (c == '(') {
        while (!stack.empty() && stack.top() != ')') {
          stack.pop();
        }
      }
    }

    return stack.empty();
  }
};

int main(int argc, char const *argv[]) {
  string s{"()"};
  cout << boolalpha;
  cout << (new Solution)->isValid(s) << endl;
  return 0;
}
