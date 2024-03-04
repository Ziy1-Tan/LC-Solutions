/*
 * @lc app=leetcode.cn id=703 lang=cpp
 *
 * [703] 数据流中的第 K 大元素
 */

// @lc code=start
#include <queue>
#include <vector>
using namespace std;

class KthLargest {
 public:
  KthLargest(int k, vector<int>& nums) : k_(k) {
    for (auto& n : nums) {
      q_.push(n);
      if (q_.size() > k) {
        q_.pop();
      }
    }
  }

  int add(int val) {
    q_.push(val);
    if (q_.size() > k_) {
      q_.pop();
    }

    return q_.top();
  }

 private:
  int k_;
  priority_queue<int, vector<int>, greater<int>> q_;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end
