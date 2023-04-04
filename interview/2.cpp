#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>
using namespace std;
/**
 *  面试官给你发消息了
 * 
 * 该线程池使用一个队列来存储任务，同时使用条件变量来阻塞线程直到有任务可执行。
 * enqueue()方法被用来将任务添加到队列中。
 * 线程池的析构函数首先向队列中添加一个停止信号，
 * 然后唤醒所有线程，等待它们完成当前任务并退出。
 */
class ThreadPool {
 public:
  ThreadPool(size_t num_threads) : stop(false) {
    for (size_t i = 0; i < num_threads; ++i)
    // 每个线程不断从队列里面拿任务运行
      threads.emplace_back([this] {
        // 这里就是你写的task函数！！！！！
        for (;;) {
          function<void()> task;
          {
            unique_lock<mutex> lock(this->queue_mutex);
            // 等价于while(!stop&&task.empty()) {condition.wait(lock);}
            // 没有任务的时候线程阻塞
            this->condition.wait(
                lock, [this] { return this->stop ||
                 !this->tasks.empty(); });
            if (this->stop && this->tasks.empty()) return;
            // 从队列里面取出队头元素
            task = move(this->tasks.front());
            this->tasks.pop();
          }
        // 取到任务就调用！！！
          task();
        }
      });
  }

  // AddTask记得条件变量唤醒！！！！！
  template <class F>
  void enqueue(function<void()> f) {
    {
      // RAII，unique_lock超出作用域自动解锁
      unique_lock<mutex> lock(queue_mutex);
      tasks.emplace(forward<F>(f));
    }
    // 新加入了元素，队列不为空，可以唤醒被阻塞的线程了
    condition.notify_one();
  }

// 停止的时候要join所有线程！！！！！记得加锁！！！！！！构造函数里也要加！！！
  ~ThreadPool() {
    {
      unique_lock<mutex> lock(queue_mutex);
      stop = true;
    }
    condition.notify_all();
    for (auto& thread : threads) thread.join();
  }

 private:
  vector<thread> threads;
  queue<function<void()>> tasks;

  mutex queue_mutex;
  condition_variable condition;
  bool stop;
};
