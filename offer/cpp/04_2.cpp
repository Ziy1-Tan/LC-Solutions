// 利用二叉搜索树的性质，从左下或右上搜索元素
// 时间复杂度O(N+M)
// 空间复杂度O(1)
#include <ios>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool findNumberIn2DArray(vector<vector<int>> &matrix, int target) {
    if (matrix.size() == 0 || matrix[0].size() == 0)
      return false;
    int i = matrix.size() - 1, j = 0;
    while (i >= 0 && j <= matrix[0].size() - 1) {
      if (matrix[i][j] > target)
        i--;
      else if (matrix[i][j] < target)
        j++;
      else
        return true;
    }
    return false;
  };
};

int main(int argc, const char *argv[]) {
  vector<vector<int>> nums{{1, 4, 7, 11, 15},
                           {2, 5, 8, 12, 19},
                           {3, 6, 9, 16, 22},
                           {10, 13, 14, 17, 24},
                           {18, 21, 23, 26, 30}};
  bool res = (new Solution)->findNumberIn2DArray(nums, 30);

  cout << boolalpha << res << endl;
  return 0;
}