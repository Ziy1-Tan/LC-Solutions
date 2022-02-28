// 最小堆实现，维护一个大小为K的最小堆，nums元素依次入堆，堆顶即为第K大的元素
// 当前元素比堆顶小时不入堆，堆元素个数大于K时弹出堆顶
// 时间复杂度 O(NlogK)
// 空间复杂度 O(K)
#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  int findKthLargest(vector<int> &nums, int k) {
    if (k > nums.size())
      return -1;

    // 小根堆定义
    priority_queue<int, vector<int>, greater<>> pq;

    for (const auto &num : nums) {
      // 当前元素比堆顶大才会入堆
      if (pq.empty() || pq.size() < k || num > pq.top()) {
        pq.push(num);
      }

      if (pq.size() > k) {
        pq.pop();
      }
    }
    return pq.top();
  }
};

int main(int argc, const char *argv[]) {
  vector<int> nums{3, 2, 1, 5, 6, 4};
  cout << (new Solution())->findKthLargest(nums, 2) << endl;
  return 0;
}