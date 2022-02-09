#include <iostream>
#include <stack>
using namespace std;

class CQueue {
public:
  CQueue() {}

  void appendTail(int value) { data.push(value); }

  int deleteHead() {
    while (!data.empty()) {
      tmp.push(data.top());
      data.pop();
    }

    if (tmp.empty())
      return -1;

    int del = tmp.top();
    tmp.pop();

    while (!tmp.empty()) {
      data.push(tmp.top());
      tmp.pop();
    }
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