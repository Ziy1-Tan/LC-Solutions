#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix.front().size();
    // 从右上角开始
    int i = m - 1, j = 0;
    while (i >= 0 && j <= n - 1) {
      // 左子树
      if (matrix[i][j] > target) {
        i--;
        // 右子树
      } else if (matrix[i][j] < target) {
        j++;
      } else
        return true;
    }
    return false;
  }
};
// 2 逐行二分
int main(int argc, char const* argv[]) {
  vector<vector<int>> matrix = {
      {5},
  };
  cout << boolalpha;
  cout << (new Solution)->searchMatrix(matrix, -5) << endl;
  cout << (new Solution)->searchMatrix(matrix, 9) << endl;
  return 0;
}
