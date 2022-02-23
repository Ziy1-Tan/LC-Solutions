// 利用两个栈实现最小栈，栈A保存正常数据，栈B维护历史最小值
// 栈A维护栈的正常操作，核心在于如何维护栈B
// push时，若push的值比栈B栈顶元素值小，则值压入栈B中
// pop时，若pop值与栈B栈顶相同，则栈B执行pop操作
// 栈B栈顶即为MinStack最小值
// 空间复杂度O(N),若一直降序压入数据，栈B使用空间最多
#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;

class MinStack {
public:
  /** initialize your data structure here. */
  MinStack() {
    top1 = -1;
    top2 = -1;
    minVal = INT_MAX;
  }

  void push(int x) {
    if (top1 >= MAX_SIZE)
      return;
    data1[++top1] = x;
    if (minVal >= x) {
      minVal = x;
      data2[++top2] = minVal;
    }
  }

  void pop() {
    if (top1 < 0)
      return;
    if (data1[top1--] == minVal) {
      if (--top2 < 0)
        minVal = INT_MAX;
      else
        minVal = data2[top2];
    }
  }

  int top() {
    if (top1 < 0)
      return -1;
    return data1[top1];
  }

  int min() { return minVal; }

  static const int MAX_SIZE = 20000;
  int data1[MAX_SIZE];
  int top1;
  int data2[MAX_SIZE];
  int top2;
  int minVal;
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