#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    int n = nums.size();
    int target = n - k;
    int start = 0, end = n - 1;
    while (true) {
      int p = partition(nums, start, end);
      if (p == target) {
        return nums[p];
      } else if (p < target) {
        start = p + 1;
      } else {
        end = p - 1;
      }
    }
    return -1;
  }

  int partition(vector<int>& nums, int start, int end) {
    int pivot = nums[start];
    int l = start + 1, r = end;
    while (true) {
      while (l <= r && nums[l] < pivot) l++;
      while (l <= r && nums[r] > pivot) r--;
      if (l >= r) break;
      swap(nums[l], nums[r]);
      l++;
      r--;
    }
    swap(nums[start], nums[r]);
    return r;
  }
};

class Solution2 {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> heap;
    for (const auto& num : nums) {
      heap.push(num);
      if (heap.size() > k) {
        heap.pop();
      }
    }
    return heap.top();
  }
};

int main(int argc, char const* argv[]) {
  vector<int> v{3, 2, 1, 6, 5, 4};
  cout << (new Solution2)->findKthLargest(v, 3) << endl;
  return 0;
}
