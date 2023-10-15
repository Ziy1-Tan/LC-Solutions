#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  int search(vector<int>& nums, int target) {
    if (nums.empty()) return -1;
    if (nums.size() == 1) return nums.front() == target ? 0 : -1;
    int n = nums.size();
    int start = 0, end = n - 1;
    while (start <= end) {
      int mid = (start + end) / 2;
      if (nums[mid] == target) {
        return mid;
      }
      // 前半部分有序 2,3,4,5,6,7,1
      if (nums[start] <= nums[mid]) {
        // target在前半部分
        if (nums[start] <= target && target < nums[mid]) {
          end = mid - 1;
        } else {
          start = mid + 1;
        }
        // 后半部分有序
      } else {
        // target在后半部分
        if (nums[mid] < target && target <= nums[end]) {
          start = mid + 1;
        } else {
          end = mid - 1;
        }
      }
    }
    return -1;
  }
};

int main(int argc, char const* argv[]) {
  vector<int> v1{5, 6, 7, 1, 2, 3, 4};
  vector<int> v2{4, 5, 6, 7, 0, 1, 2};
  cout << (new Solution)->search(v2, 0) << endl;
  return 0;
}
