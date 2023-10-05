/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// 依次计算每个格子能装多少水，判断height[i] <
// min(maxLeft[i],maxRight[i])即可装水
class Solution {
 public:
  int trap(vector<int> &height) {
    if (height.empty()) {
      return 0;
    }
    int n = height.size();
    int ans = 0;
    vector<int> maxLeft(n);
    vector<int> maxRight(n);
    maxLeft[0] = height[0];
    maxRight[n - 1] = height[n - 1];

    for (int i = 1; i < n; i++) {
      maxLeft[i] = max(maxLeft[i - 1], height[i]);
    }

    for (int i = n - 2; i >= 0; i--) {
      maxRight[i] = max(maxRight[i + 1], height[i]);
    }

    for (int i = 1; i < n; i++) {
      if (min(maxLeft[i], maxRight[i]) > height[i]) {
        ans += min(maxLeft[i], maxRight[i]) - height[i];
      }
    }

    return ans;
  }
};

// dp空间优化版
class Solution2 {
 public:
  int trap(vector<int> &height) {
    if (height.empty()) {
      return 0;
    }
    int n = height.size();
    int ans = 0;
    int left = 0, right = n - 1;
    int maxLeft = height[left], maxRight = height[right];

    while (left <= right) {
      maxLeft = max(maxLeft, height[left]);
      maxRight = max(maxRight, height[right]);

      // 对于0...left来说，有比maxLeft更高的柱子，那么只需要判断是否maxLeft比当前位置要高即可装下水
      if (maxLeft < maxRight) {
        ans += maxLeft - height[left];
        left++;
      } else {
        ans += maxRight - height[right];
        right--;
      }
    }

    return ans;
  }
};

class Solution3 {
 public:
  int trap(vector<int> &height) {
    if (height.empty()) {
      return 0;
    }
    int n = height.size();
    int ans = 0;
    // 元素索引，栈顶->栈底降序排列，当前元素>栈顶时出栈计算
    stack<int> st;
    for (int i = 0; i < n; i++) {
      // 对 [0,1,0,0,3] 也适用
      while (!st.empty() && height[st.top()] < height[i]) {
        int curr = st.top();
        st.pop();
        if (st.empty()) {
          break;
        }
        int l = st.top();
        // 左右最高柱子较小 - 当前高度的差 = 能装的水
        int h = min(height[l], height[i]) - height[curr];
        ans += (i - l - 1) * h;
      }
      st.push(i);
    }

    return ans;
  }
};
// @lc code=end
