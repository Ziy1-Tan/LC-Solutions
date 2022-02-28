// 利用一个大小为K大根堆维护最小的K个数，每个数依次入堆，
// 当数大于堆顶时不入堆，当堆的大小大于K时堆顶弹出(注意使用最小堆需要把所有元素压入后弹出k个元素，复杂度为O(NlogN))
// 时间复杂度 O(NlogK) 入堆操作NlogK,出堆操作KlogK
// 空间复杂度 O(K)
#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> getLeastNumbers(vector<int> &arr, int k) {
    if (k >= arr.size())
      return arr;

    // 入堆操作
    priority_queue<int> pq;
    for (const auto &num : arr) {
      // 如果当前元素小于堆顶才会入堆
      if (pq.empty() || pq.size() < k || num < pq.top()) {
        pq.push(num);
      }

      // 保持堆大小为K
      if (pq.size() > k)
        pq.pop();
    }
    // 弹出K个元素

    vector<int> res(k);
    int i = 0;
    while (!pq.empty()) {
      res[i++] = pq.top();
      pq.pop();
    }
    return res;
  }
};

int main(int argc, const char *argv[]) {
  vector<int> arr{4, 5, 1, 6, 2, 7, 3, 8};
  auto res = (new Solution())->getLeastNumbers(arr, 5);
  for (auto e : res) {
    cout << e << endl;
  }
  return 0;
}