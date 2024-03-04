/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */

// @lc code=start
#include <stack>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<int> nextGreaterElements(vector<int> &nums) {
    int n = nums.size();
    vector<int> res(n, -1);
    stack<int> st;
    for (int i = 0; i < 2 * n; i++) {
      while (!st.empty() && nums[i % n] > nums[st.top()]) {
        int u = st.top();
        st.pop();
        res[u] = nums[i % n];
      }
      st.push(i % n);
    }
    return res;
  }
};
// @lc code=end
