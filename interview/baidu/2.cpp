#include <iostream>
using namespace std;

int expand(const string& s, int i, int j) {
  int cnt = 0;
  while (i >= 0 && j < s.size() && s[i] == s[j]) {
    i--;
    j++;
    cnt++;
  }
  return cnt;
}

int solve(const string& s) {
  int cnt = 0;
  for (int i = 0; i < s.size(); i++) {
    cnt += expand(s, i, i);
    cnt += expand(s, i, i + 1);
  }
  return cnt;
}

int main() {
  int n;
  cin >> n;
  int cnt = 0;
  for (int i = 0; i <= n; i++) {
    if ((i * (i + 1)) / 2 > n) {
      cnt = i - 1;
      break;
    }
  }

  string ans(cnt, 'r');
  int rest = n - (cnt * (cnt + 1)) / 2;
  string str = "der";
  int j = 0;
  for (int i = 0; i < rest; i++) {
    ans.push_back(str[j]);
    j = (j + 1) % 3;
  }

  cout << ans << endl;

  return 0;
}
