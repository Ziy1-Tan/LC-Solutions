/*
 * @lc app=leetcode.cn id=301 lang=cpp
 *
 * [301] 删除无效的括号
 */

// @lc code=start
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  unordered_set<string> set;
  int maxLen, maxScore, n;
  string str;
  vector<string> removeInvalidParentheses(string s) {
    str = s;
    n = s.size();
    int l = 0, r = 0;
    for (auto& i : s) {
      if (i == '(') {
        l++;
      }
      if (i == ')') {
        if (l != 0) {
          l--;
        } else {
          r++;
        }
      }
    }

    maxLen = n - l - r;

    int c1, c2;
    for (auto& i : s) {
      if (i == '(') {
        c1++;
      }
      if (i == ')') {
        c2++;
      }
    }

    maxScore = min(c1, c2);

    dfs(0, l, r, 0, "");
    vector<string> res;
    for_each(set.begin(), set.end(), [&](auto& i) { res.push_back(i); });
    return res;
  }

  void dfs(int i, int l, int r, int score, string tmp) {
    if (l < 0 || r < 0 || score < 0 || score > maxScore) {
      return;
    }

    if (l == 0 && r == 0) {
      if (tmp.size() == maxLen) {
        set.insert(tmp);
      }
    }

    if (i == n) {
      return;
    }

    if (str[i] == '(') {
      dfs(i + 1, l, r, score + 1, tmp + str[i]);
      // 是 '(' 但是不选，需要删掉的 '(' 数量 - 1
      dfs(i + 1, l - 1, r, score, tmp);
    } else if (str[i] == ')') {
      dfs(i + 1, l, r, score - 1, tmp + str[i]);
      dfs(i + 1, l, r - 1, score, tmp);
    } else {
      dfs(i + 1, l, r, score, tmp + str[i]);
    }
  }
};
// @lc code=end
