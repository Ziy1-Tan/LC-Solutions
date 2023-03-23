#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

vector<pair<int, int>> isP(const string& s) {
  int n = s.size();
  vector<pair<int, int>> ans;
  int l = 0, r = n - 1;
  while (l <= r) {
    if (s[l] != s[r]) {
      ans.push_back(make_pair(l, r));
    }
    l++;
    r--;
  }
  return ans;
}

string solve(string& s) {
  vector<pair<int, int>> ans = isP(s);
  int cnt = ans.size();
  if (cnt == 0) {
    int l = 0, r = s.size() - 1;
    while (l <= r) {
      if (s[l] != 'a') {
        s[l] = s[r] = 'a';
        break;
      }
      l++;
      r--;
    }
    return s;
  }
  if (cnt == 1) {
    int l = ans[0].first, r = ans[0].second;
    if (s[l] == 'a' || s[r] == 'a') {
      s[l] = s[r] = 'a';
      if (s.size() % 2 == 1) {
        s[s.size() / 2] = 'a';
      }
    } else {
      s[l] = s[r] = 'a';
    }
  } else if (cnt == 2) {
    int l1 = ans[0].first, r1 = ans[0].second;
    int l2 = ans[1].first, r2 = ans[1].second;
    if (s[l1] < s[r1])
      s[r1] = s[l1];
    else
      s[l1] = s[r2];
    if (s[l2] < s[r2])
      s[r2] = s[l2];
    else
      s[l2] = s[r2];
  }
  return s;
}

int main(int argc, char const* argv[]) {
  string s;
  cin >> s;
  cout << solve(s) << endl;
  return 0;
}
