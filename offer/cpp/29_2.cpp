// 用四个变量作为上下左右边界约束打印范围
// 时间复杂度O(MN)
// 空间复杂度O(1)
#include <climits>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    vector<int> res;
    if (matrix.size() == 0)
      return res;
    int t = 0, b = matrix.size() - 1, l = 0, r = matrix[0].size() - 1;
    while (true) {
      for (int i = l; i <= r; i++) {
        res.push_back(matrix[t][i]);
      }
      if (++t > b)
        break;
      for (int i = t; i <= b; i++) {
        res.push_back(matrix[i][r]);
      }
      if (l > --r)
        break;
      for (int i = r; i >= l; i--) {
        res.push_back(matrix[b][i]);
      }
      if (--b < t)
        break;
      for (int i = b; i >= t; i--) {
        res.push_back(matrix[i][l]);
      }
      if (++l > r)
        break;
    }
    return res;
  }
};

int main(int argc, const char *argv[]) {
  vector<vector<int>> m{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  auto res = (new Solution())->spiralOrder(m);
  for (auto i : res) {
    cout << i << " ";
  }
  return 0;
}