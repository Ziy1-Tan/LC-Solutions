#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

condition_variable cv;
mutex mtx;
char flag = 'A';

void printA() {
  unique_lock<mutex> lk(mtx);
  while (true) {
    cv.wait(lk, [&]() { return flag == 'A'; });
    cout << 'A' << '\n';
    flag = 'B';
    this_thread::sleep_for(std::chrono::seconds(1));
    cv.notify_all();
  }
}

void printB() {
  unique_lock<mutex> lk(mtx);
  while (true) {
    cv.wait(lk, [&]() { return flag == 'B'; });
    cout << 'B' << '\n';
    flag = 'A';
    this_thread::sleep_for(std::chrono::seconds(1));
    cv.notify_all();
  }
}

int main(int argc, char const *argv[]) {
  thread thA(printA);
  thread thB(printB);
  thA.join();
  thB.join();
  return 0;
}
