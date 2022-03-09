// queue+deque实现，queue存储数据，deque存储维护队列元素的递增序列
// max_value： deque的队头元素
// push_back： queue正常插入，元素插入到适当的位置，使得队列中为递增序列
// pop_back： queue正常弹出，若queue队头元素与deque队头元素相等，则deque弹出
// 时间：max_value O(1) push_back O(1)(543216,只有最后一次时间复杂度为O(N)，(((N-1)O(1)+O(N))/N=O(1))) pop_back O(1)
// 空间：O(N)
#include <deque>
#include <iostream>
#include <queue>
using namespace std;

class MaxQueue {
public:
  MaxQueue() {}

  int max_value() { return helper.empty() ? -1 : helper.front(); }

  void push_back(int value) {
    data.push(value);
    while (!helper.empty() && helper.back() < value)
      helper.pop_back();
    helper.push_back(value);
  }

  int pop_front() {
    if (data.empty())
      return -1;

    int pop = data.front();
    data.pop();

    if (helper.front() == pop)
      helper.pop_front();

    return pop;
  }

private:
  queue<int> data;
  deque<int> helper;
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */

int main(int argc, const char *argv[]) {
  MaxQueue mq;
  mq.push_back(3);
  mq.push_back(3);
  mq.push_back(1);
  mq.push_back(2);
  cout << mq.max_value() << endl;
  mq.push_back(4);
  cout << mq.max_value() << endl;
  return 0;
}