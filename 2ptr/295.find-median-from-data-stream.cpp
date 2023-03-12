#include <queue>
using namespace std;

class MedianFinder {
 public:
  MedianFinder() {}

  void addNum(int num) {
    if (l.size() == r.size()) {
      if (r.empty() || num <= r.top()) {
        l.push(num);
      } else {
        l.push(r.top());
        r.pop();
        r.push(num);
      }
    } else {
      if (num >= l.top()) {
        r.push(num);
      } else {
        r.push(l.top());
        l.pop();
        l.push(num);
      }
    }
  }

  double findMedian() {
    return l.size() == r.size() ? static_cast<double>((l.top() + r.top())) / 2.0
                                : l.top();
  }

 private:
  priority_queue<int> l;
  priority_queue<int, vector<int>, greater<int>> r;
};
