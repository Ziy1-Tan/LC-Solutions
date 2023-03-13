#include <cctype>
#include <iostream>
using namespace std;

int main() {
  string s;
  cin >> s;
  string ans;
  int cnt = 0;
  for (char c : s) {
    if (isdigit(c)) {
      cnt = 10 * cnt + (c - '0');
    } else {
      ans.append(string(cnt, c));
      cnt = 0;
    }
  }
  cout << ans << endl;
  return 0;
}
