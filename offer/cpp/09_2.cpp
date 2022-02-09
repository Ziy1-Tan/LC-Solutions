// 两个栈，一个栈A负责入队功能，一个栈B负责出队
// 入队时，栈A直接将元素入栈
// 出队时（1）栈B不为空，栈顶元素即为队头元素（2）栈B、栈A为空，返回-1（3）栈A不为空栈B为空，将A中元素依次处栈后加入B，B栈顶元素即为队头元素
// 时间复杂度：入栈O(1),出栈O(N)
// 空间复杂度: O(N)
#include <iostream>
#include <stack>
using namespace std;

class CQueue {
public:
  CQueue() {}

  void appendTail(int value) { data.push(value); }

  int deleteHead() {
    if (!tmp.empty()) {
      int del = tmp.top();
      tmp.pop();
      return del;
    }

    if (data.empty())
      return -1;

    while (!data.empty()) {
      tmp.push(data.top());
      data.pop();
    }
    int del = tmp.top();
    tmp.pop();
    return del;
  }

private:
  stack<int> data;
  stack<int> tmp;
};

int main(int argc, const char *argv[]) {
  CQueue *q = new CQueue();
  q->appendTail(3);
  q->appendTail(2);
  cout << q->deleteHead() << endl;
  cout << q->deleteHead() << endl;
  return 0;
}