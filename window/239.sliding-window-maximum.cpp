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
    // 队头->队尾 单调递减
    for (size_t i = 0; i < k; i++) {
      while (!que.empty() && nums[i] > que.back()) {
        que.pop_back();
      }
      que.push_back(nums[i]);
    }

    vector<int> res{que.front()};
    for (int i = k; i < nums.size(); i++) {
      // 从队列中删除nums[i-k]
      if (!que.empty() && que.front() == nums[i - k]) {
        que.pop_front();
      }
      // 插入元素nums[i]
      while (!que.empty() && nums[i] > que.back()) {
        que.pop_back();
      }
      que.push_back(nums[i]);
      res.push_back(que.front());
    }
    return res;
  }
};
