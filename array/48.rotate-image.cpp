#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
 public:
  void rotate(vector<vector<int>> &matrix) {
    if (matrix.empty()) {
      return;
    }
    int n = matrix.size();
    // 转置
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        swap(matrix[i][j], matrix[j][i]);
      }
    }

    // 镜像翻转
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n / 2; j++) {
        swap(matrix[i][j], matrix[i][n - 1 - j]);
      }
    }
  }
};

int main(int argc, char const *argv[]) {
  vector<vector<int>> matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  (new Solution)->rotate(matrix);
  auto pv = [](const auto res) {
    for (auto &&i : res) cout << i << " ";
    cout << '\n';
  };
  for (auto &&r : matrix) {
    pv(r);
  }

  return 0;
}
