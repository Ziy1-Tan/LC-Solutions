#include <iostream>
#include <memory>
#include <vector>

using namespace std;
class Solution {
 public:
  int countSubstrings(string s) {
    if (s.size() < 2) return 1;

    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n));
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      dp[i][i] = 1;
    }

    for (int i = n - 1; i >= 0; i--)
      for (int j = i; j < n; j++)
        if (s[i] == s[j] && (j - i < 3 || dp[i + 1][j - 1])) {
          dp[i][j] = 1;
          cnt++;
        }

    return cnt;
  }
};

class Solution2 {
 public:
  int countSubstrings(string s) {
    if (s.size() < 2) return 1;

    int n = s.size();
    for (int i = 0; i < s.size(); i++) {
      expand(s, i, i);
      expand(s, i, i + 1);
    }

    return cnt;
  }

 private:
  int cnt = 0;
  void expand(const string &s, int l, int r) {
    while (l >= 0 && r < s.size() && s[l--] == s[r++]) {
      cnt++;
    }
  }
};

int main(int argc, char const *argv[]) {
  shared_ptr<int> sp;
  cout << (new Solution2)->countSubstrings("aaa") << endl;
  return 0;
}
