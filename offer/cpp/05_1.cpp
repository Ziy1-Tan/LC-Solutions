#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  string replaceSpace(string s) {
    string res;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == ' ') {
        res.push_back('%');
        res.push_back('2');
        res.push_back('0');
      } else {
        res.push_back(s[i]);
      }
    }
    return res;
  }
};

int main(int argc, const char *argv[]) {
  string s = "We are happy.";
  auto res = (new Solution)->replaceSpace(s);
  cout << res << endl;
  return 0;
}