#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  int search(vector<int>& nums, int target) {
    if (nums.empty()) return -1;
    if (nums.size() == 1) return nums.front() == target ? 0 : -1;
    int n = nums.size();
    int l = 0, r = n - 1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (nums[mid] == target) {
        return mid;
      }

      if (nums[l] <= nums[mid]) {
        if (nums[l] <= target && target < nums[mid]) {
          r = mid - 1;
        } else {
          l = mid + 1;
        }
      } else {
        if (nums[mid] < target && target <= nums[r]) {
          l = mid + 1;
        } else {
          r = mid - 1;
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
