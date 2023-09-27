/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int longestValidParentheses(string s) {
    stack<int> st;
    int start = 0;
    int maxLen = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(') {
        st.push(i);
      } else {
        if (st.empty()) {
          start = i + 1;
        } else {
          st.pop();
          if (st.empty()) {
            maxLen = max(maxLen, i - start + 1);
          } else {
            // (((()
            maxLen = max(maxLen, i - st.top());  // i - (st.top() +1) + 1
          }
        }
      }
    }

    return maxLen;
  }
};

class Solution2 {
 public:
  int longestValidParentheses(string s) {
    int n = s.size();
    int maxLen = 0;
    vector<int> dp(n);
    for (int i = 1; i < n; i++) {
      if (s[i] == ')') {
        if (s[i - 1] == '(') {
          dp[i] = (i - 2 >= 0 ? dp[i - 2] : 0) + 2;
        } else if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(') {
          dp[i] = dp[i - 1] +
                  (i - dp[i - 1] - 2 >= 0 ? dp[i - dp[i - 1] - 2] : 0) + 2;
        }
        maxLen = max(maxLen, dp[i]);
      }
    }

    return maxLen;
  }
};
// @lc code=end
