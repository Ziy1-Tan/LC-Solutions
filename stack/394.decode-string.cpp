#include <cctype>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
 public:
  string decodeString(string s) {
    string res;
    stack<int> numStack;
    stack<string> stack;
    int num = 0;
    for (auto &c : s) {
      if (isalpha(c) && numStack.empty()) {
        res += c;
      } else if (isdigit(c)) {
        num = num * 10 + (c - '0');
      } else if (c == '[') {
        stack.push("[");
        numStack.push(num);
        num = 0;
      } else if (c == ']') {
        string tmp;
        while (!stack.empty()) {
          string curr = stack.top();
          stack.pop();
          if (curr == "[") {
            int cnt = numStack.top();
            numStack.pop();
            string sum = "";
            for (int i = 0; i < cnt; i++) {
              sum += tmp;
            }
            if (numStack.empty()) {
              res += sum;
            } else {
              stack.push(sum);
            }
            break;
          } else {
            tmp = curr + tmp;
          }
        }
      } else {
        stack.push(string("") + c);
      }
    }

    return res;
  }
};

int main(int argc, char const *argv[]) {
  cout << (new Solution)->decodeString("3[a]2[1[b]1[c]]") << endl;
  return 0;
}
