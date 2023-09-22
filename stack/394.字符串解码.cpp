#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
  string decodeString(string s) {
    string res;
    stack<int> nums;
    stack<string> strs;
    int num = 0;
    for (auto &c : s) {
      if (c >= '0' && c <= '9') {
        num = num * 10 + (c - '0');
      } else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        res += c;
      } else if (c == '[') {
        nums.push(num);
        num = 0;
        strs.push(res);
        res = "";
      } else if (c == ']') {
        int times = nums.top();
        nums.pop();
        for (size_t i = 0; i < times; i++) {
          strs.top().append(res);
        }
        res = strs.top();
        strs.pop();
      }
    }
    return res;
  }
};

int main(int argc, const char *argv[]) {
  cout << (new Solution)->decodeString("3[a2[b]]2[c]") << endl;
  return 0;
}
