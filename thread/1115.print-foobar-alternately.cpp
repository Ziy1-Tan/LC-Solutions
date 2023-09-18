#include <condition_variable>
#include <functional>
#include <mutex>
using namespace std;

class FooBar {
 private:
  int n;
  mutex mtx;
  condition_variable cv;
  int flag = 0;

 public:
  FooBar(int n) { this->n = n; }

  void foo(function<void()> printFoo) {
    for (int i = 0; i < n; i++) {
      unique_lock<mutex> lk(mtx);
      cv.wait(lk, [this]() { return flag == 0; });
      // printFoo() outputs "foo". Do not change or remove this line.
      printFoo();
      flag = 1;
      cv.notify_one();
    }
  }

  void bar(function<void()> printBar) {
    for (int i = 0; i < n; i++) {
      unique_lock<mutex> lk(mtx);
      cv.wait(lk, [this]() { return flag == 1; });
      // printBar() outputs "bar". Do not change or remove this line.
      printBar();
      flag = 0;
      cv.notify_one();
    }
  }
};
