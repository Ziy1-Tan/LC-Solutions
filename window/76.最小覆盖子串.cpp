/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  string minWindow(string s, string t) {
    if (s.size() < t.size()) {
      return "";
    }
    unordered_map<char, int> c2;
    int cnt = 0;
    for (auto &&c : t) {
      if (++c2[c] == 1) {
        cnt++;
      }
    }

    unordered_map<char, int> c1;
    string res = "";
    for (int l = 0, r = 0; r < s.size(); r++) {
      c1[s[r]]++;
      if (c1[s[r]] == c2[s[r]]) {
        cnt--;
      }
      while (l < r) {
        if (c1[s[l]] > c2[s[l]] && --c1[s[l]] >= 0) {
          l++;
        } else {
          break;
        }
      }
      if (cnt == 0) {
        if (res.empty() || res.size() > r - l + 1) {
          res = s.substr(l, r - l + 1);
        }
      }
    }
    return res;
  }
};
// @lc code=end
