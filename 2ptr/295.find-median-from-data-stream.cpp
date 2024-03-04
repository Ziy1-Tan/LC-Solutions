#include <queue>
using namespace std;

class MedianFinder {
 public:
  MedianFinder() {}

  void addNum(int num) {
    if (leftPq.size() == rightPq.size()) {
      // 不在后半部分
      if (leftPq.empty() || num < rightPq.top()) {
        leftPq.push(num);
      } else {
        leftPq.push(rightPq.top());
        rightPq.pop();
        rightPq.push(num);
      }
    } else {
      // 不在前半部分
      if (num > leftPq.top()) {
        rightPq.push(num);
      } else {
        rightPq.push(leftPq.top());
        leftPq.pop();
        leftPq.push(num);
      }
    }
  }

  double findMedian() {
    return leftPq.size() == rightPq.size()
               ? static_cast<double>(leftPq.top() + rightPq.top()) / 2.0
               : leftPq.top();
  }

 private:
  priority_queue<int> leftPq;
  priority_queue<int, vector<int>, greater<int>> rightPq;
};
