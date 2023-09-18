#include <algorithm>
#include <iostream>
#include <string>

using namespace std;
class Solution {
 public:
  string reverseWords(string s) {
    int n = s.size(), i = 0;
    string ans = "", tmp = "";
    while (i < n) {
      tmp = "";
      while (i < n && s[i] == ' ') i++;
      while (i < n && s[i] != ' ') tmp += s[i++];
      if (!tmp.empty()) {
        ans = tmp + " " + ans;
      }
    }
    ans.pop_back();
    return ans;
  }
};

int main(int argc, char const *argv[]) {
  cout << (new Solution)->reverseWords("  hello world  ") << endl;
  return 0;
}
