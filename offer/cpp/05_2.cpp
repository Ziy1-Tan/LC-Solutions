#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  string replaceSpace(string s) {
    int cnt = 0;
    int sOldSize = s.size();
    for (int i = 0; i < sOldSize; i++) {
      if (s[i] == ' ')
        cnt++;
    }

    s.resize(sOldSize + cnt * 2);

    int sNewSize = s.size();

    for (int i = sOldSize - 1, j = sNewSize - 1; i < j; i--, j--) {
      if (s[i] != ' ') {
        s[j] = s[i];
      } else {
        s[j] = '0';
        s[j - 1] = '2';
        s[j - 2] = '%';
        j -= 2;
      }
    }
    return s;
  }
};

int main(int argc, const char *argv[]) {
  string s = "We are happy.";
  auto res = (new Solution)->replaceSpace(s);
  cout << res << endl;
  return 0;
}