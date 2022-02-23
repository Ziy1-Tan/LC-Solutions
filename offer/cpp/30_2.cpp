// 利用两个栈实现最小栈，栈A保存正常数据，栈B维护历史最小值
// 栈A维护栈的正常操作，核心在于如何维护栈B
// push时，若push的值比栈B栈顶元素值小，则值压入栈B中
// pop时，若pop值与栈B栈顶相同，则栈B执行pop操作
// 栈B栈顶即为MinStack最小值
// 空间复杂度O(N),若一直降序压入数据，栈B使用空间最多
#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:
  MinStack() {}

  void push(int x) {
    a.push(x);
    // 有更小的值
    if (b.empty() || x <= b.top()) {
      b.push(x);
    }
  }

  void pop() {
    int tmp = a.top();
    a.pop();
    if (tmp == b.top()) {
      b.pop();
    }
  }

  int top() { return a.top(); }

  int min() { return b.top(); }

private:
  stack<int> a;
  stack<int> b;
};

int main(int argc, const char *argv[]) {
  auto s = new MinStack();
  s->push(2147483646);
  s->push(2147483646);
  s->push(2147483647);
  cout << s->min() << endl;
  s->pop();
  cout << s->top() << endl;
  cout << s->min() << endl;
  return 0;
}