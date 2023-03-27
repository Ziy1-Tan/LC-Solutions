#include <condition_variable>
#include <functional>
#include <iostream>
#include <mutex>
#include <thread>
using namespace std;
class Foo {
 public:
  Foo() {}

  void first(function<void()> printFirst) {
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    unique_lock<mutex> lk(mtx);
    k = 1;
    cv.notify_all();
  }

  void second(function<void()> printSecond) {
    unique_lock<mutex> lk(mtx);
    cv.wait(lk, [&]() { return k == 1; });
    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    k = 2;
    cv.notify_all();
  }

  void third(function<void()> printThird) {
    unique_lock<mutex> lk(mtx);
    cv.wait(lk, [&]() { return k == 2; });
    // printThird() outputs "third". Do not change or remove this line.
    printThird();
  }

 private:
  mutex mtx;
  condition_variable cv;
  int k = 0;
};
