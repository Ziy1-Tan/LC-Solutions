#include <condition_variable>
#include <functional>
#include <mutex>
using namespace std;

class ZeroEvenOdd {
 private:
  int n;
  int flag{0};
  mutex mtx;
  condition_variable cv;

 public:
  ZeroEvenOdd(int n) { this->n = n; }

  // printNumber(x) outputs "x", where x is an integer.
  void zero(function<void(int)> printNumber) {
    for (int i = 1; i <= n; i++) {
      unique_lock<mutex> lk(mtx);
      cv.wait(lk, [this]() { return flag == 0; });
      printNumber(0);
      flag = i % 2 == 0 ? 2 : 1;
      cv.notify_all();
    }
  }

  void even(function<void(int)> printNumber) {
    for (int i = 2; i <= n; i += 2) {
      unique_lock<mutex> lk(mtx);
      cv.wait(lk, [this]() { return flag == 2; });
      printNumber(i);
      flag = 0;
      cv.notify_all();
    }
  }

  void odd(function<void(int)> printNumber) {
    for (int i = 1; i <= n; i += 2) {
      unique_lock<mutex> lk(mtx);
      cv.wait(lk, [this]() { return flag == 1; });
      printNumber(i);
      flag = 0;
      cv.notify_all();
    }
  }
};
