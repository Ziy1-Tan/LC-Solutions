// 利用数组有序的性质做二分查找
// 时间复杂度O(Nlog2M)
// 空间复杂度O(1)
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool findNumberIn2DArray(vector<vector<int>> &matrix, int target) {
    int n = matrix.size();
    if (n == 0)
      return false;
    int m = matrix[0].size();
    if (m == 0)
      return false;

    for (int i = 0; i < n; i++) {
      int mid, left = 0, right = m - 1;
      while (left <= right) {
        mid = (left + right) / 2;
        if (matrix[i][mid] > target) {
          right = mid - 1;
        } else if (matrix[i][mid] < target) {
          left = mid + 1;
        } else {
          return true;
        }
      }
    }
    return false;
  }
};

int main(int argc, const char *argv[]) {
  vector<vector<int>> nums{{1, 4, 7, 11, 15},
                           {2, 5, 8, 12, 19},
                           {3, 6, 9, 16, 22},
                           {10, 13, 14, 17, 24},
                           {18, 21, 23, 26, 30}};
  bool res = (new Solution)->findNumberIn2DArray(nums, 6);

  cout << boolalpha << res << endl;
  return 0;
}