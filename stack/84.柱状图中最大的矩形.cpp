/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
 public:
  int largestRectangleArea(vector<int>& heights) {
    int res = 0;
    heights.push_back(0);
    stack<int> st;
    for (int i = 0; i < heights.size(); i++) {
      while (!st.empty() && heights[st.top()] > heights[i]) {
        int h = heights[st.top()];
        st.pop();
        if (st.empty()) {
          res = max(res, i * h);
        } else {
          res = max(res, (i - st.top() - 1) * h);
        }
      }
      st.push(i);
    }

    return res;
  }
};

// @lc code=end
