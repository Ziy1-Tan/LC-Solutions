/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
#include <iostream>
#include <stack>
using namespace std;

class MinStack {
 public:
  MinStack() {}

  void push(int val) {
    st.push(val);
    if (minSt.empty()) {
      minSt.push(val);
    } else {
      minSt.push(min(minSt.top(), val));
    }
  }

  void pop() {
    st.pop();
    minSt.pop();
  }

  int top() { return st.top(); }

  int getMin() { return minSt.top(); }

 private:
  stack<int> st;
  stack<int> minSt;
};

// int main(int argc, char const *argv[]) {
//   MinStack st;
//   st.push(-2);
//   cout << st.getMin() << endl;
//   return 0;
// }

// @lc code=end
