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
  string ans("");
  int cnt = 0;
  int step = 1;
  while (cnt + step < n) {
    ans.append("r");
    cnt += step;
    step++;
  }

  int rest = n - cnt;
  string str = "der";
  int j = 0;
  for (int i = 0; i < rest; i += 3) {
    ans.append("der");
  }

  cout << ans << endl;

  return 0;
}
