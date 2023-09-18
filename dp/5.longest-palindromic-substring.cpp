#include <iostream>
#include <string>
#include <tuple>
#include <vector>

using namespace std;
class Solution {
 public:
  string longestPalindrome(string s) {
    int n = s.size();
    if (n < 2) return s;

    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = 0; i < n; i++) dp[i][i] = 1;

    int begin = 0, maxLen = 0;
    for (int i = n - 1; i >= 0; i--)
      for (int j = i; j < n; j++)
        if (s[i] == s[j] && (j - i < 3 || dp[i + 1][j - 1])) {
          dp[i][j] = 1;
          if (j - i + 1 >= maxLen) {
            begin = i;
            maxLen = j - i + 1;
          }
        }

    return s.substr(begin, maxLen);
  }
};

class Solution2 {
 public:
  string longestPalindrome(string s) {
    if (s.size() < 2) return s;

    int begin = 0, maxLen = 0;
    for (int i = 0; i < s.size(); i++) {
      auto &&[begin1, len1] = expand(s, i, i);
      auto &&[begin2, len2] = expand(s, i, i + 1);
      int len = max(len1, len2);
      if (len > maxLen) {
        maxLen = len;
        begin = len1 > len2 ? begin1 : begin2;
      }
    }
    return s.substr(begin, maxLen);
  }

  tuple<int, int> expand(const string_view s, int left, int right) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
      left--;
      right++;
    }

    return {left + 1, right - left - 1};
  }
};

int main(int argc, char const *argv[]) {
  cout << (new Solution2)->longestPalindrome("cacc") << endl;
  return 0;
}
