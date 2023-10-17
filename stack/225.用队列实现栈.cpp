/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
#include <queue>
using namespace std;

// 栈中存储元组，可以利用单栈
class MyStack {
 public:
  MyStack() {}

  void push(int x) {
    aux.push(x);
    while (!q.empty()) {
      aux.push(q.front());
      q.pop();
    }
    swap(aux, q);
  }

  int pop() {
    int x = q.front();
    q.pop();
    return x;
  }

  int top() { return q.front(); }

  bool empty() { return q.empty(); }

 private:
  queue<int> q;
  queue<int> aux;
};

class MyStack2 {
 public:
  MyStack2() {}

  void push(int x) {
    int sz = q.size();
    q.push(x);
    for (int i = 0; i < sz; i++) {
      q.push(q.front());
      q.pop();
    }
  }

  int pop() {
    int x = q.front();
    q.pop();
    return x;
  }

  int top() { return q.front(); }

  bool empty() { return q.empty(); }

 private:
  queue<int> q;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end
