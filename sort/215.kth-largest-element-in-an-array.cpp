#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    int n = nums.size();
    int target = n - k;
    int start = 0;
    int end = n - 1;
    while (true) {
      int pivotIdx = partition(nums, start, end);
      if (pivotIdx == target) {
        return nums[pivotIdx];
      } else if (pivotIdx < target) {
        start = pivotIdx + 1;
      } else if (pivotIdx > target) {
        end = pivotIdx - 1;
      }
    }
    return -1;
  }

  int partition(vector<int>& nums, int start, int end) {
    int pivot = nums[start];
    int l = start + 1;
    int r = end;
    while (true) {
      while (l <= r && nums[l] < pivot) l++;
      while (l <= r && nums[r] > pivot) r--;
      if (l >= r) break;
      swap(nums, l, r);
      l++;
      r--;
    }
    swap(nums, start, r);
    return r;
  }

  void swap(vector<int>& nums, int i, int j) {
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
  }
};

class Solution2 {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> heap;
    for (const int num : nums) {
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
