#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    priority_queue<pair<int, int>> q;
    for (int i = 0; i < k; i++) {
      q.push({nums[i], i});
    }
    vector<int> res{q.top().first};
    for (int i = k; i < nums.size(); i++) {
      q.push({nums[i], i});
      while (q.top().second <= i - k) {
        q.pop();
      }
      res.push_back(q.top().first);
    }
    return res;
  }
};

class Solution2 {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> que;
    // 递增队列
    for (size_t i = 0; i < k; i++) {
      while (!que.empty() && nums[i] > que.back()) {
        que.pop_back();
      }
      que.push_back(nums[i]);
    }

    vector<int> res{que.front()};
    for (int i = k; i < nums.size(); i++) {
      // 窗口滑动后，从队列中删除nums[i-k]过期元素
      if (!que.empty() && que.front() == nums[i - k]) {
        que.pop_front();
      }
      // 插入滑动后新元素nums[i]
      while (!que.empty() && nums[i] > que.back()) {
        que.pop_back();
      }
      que.push_back(nums[i]);
      // 最大值始终为队头
      res.push_back(que.front());
    }
    return res;
  }
};
