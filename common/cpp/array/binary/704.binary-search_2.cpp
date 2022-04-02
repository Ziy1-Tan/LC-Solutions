#include <vector>
using namespace std;
class Solution {
public:
  int search(vector<int> &nums, int target) {
    // 左闭右开区间
    int l = 0, r = nums.size();
    while (l < r) {
      int mid = l + (r - l) / 2;
      // target在右区间，[mid+1,r) 且肯定不是nums[mid] 
      if (nums[mid] < target)
        l = mid + 1;
      else if (nums[mid] > target)
        r = mid;
      else
        return mid;
    }

    return -1;
  }
};