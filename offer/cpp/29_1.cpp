// 把当前值打印后，根据位置判断是否越界，越界则转向
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
    int n = matrix.size();
    if (n == 0) {
      return res;
    }
    int m = matrix[0].size();
    if (m == 0) {
      return res;
    }

    // 从左上角走起
    int i = 0, j = 0;

    while (res.size() != n * m) {
      if (matrix[i][j] == INT_MIN)
        break;
      res.push_back(matrix[i][j]);
      matrix[i][j] = INT_MIN;
      auto next = move(i, j);
      int ni = get<0>(next), nj = get<1>(next);
      // 判断是否越界或访问过
      if (ni == n || nj == m || ni == -1 || nj == -1 ||
          matrix[ni][nj] == INT_MIN) {
        // 转向后再移动
        flag = (flag + 1) % 4;
        next = move(i, j);
      }
      // 更新下一步位置
      i = get<0>(next);
      j = get<1>(next);
    }
    return res;
  }

  int flag = 0;
  // 根据方向返回下一步位置
  tuple<int, int> move(int i, int j) {
    tuple<int, int> t;
    switch (flag) {
    case 0:
      t = make_tuple(i, j + 1);
      break;
    case 1:
      t = make_tuple(i + 1, j);
      break;
    case 2:
      t = make_tuple(i, j - 1);
      break;
    case 3:
      t = make_tuple(i - 1, j);
      break;
    }
    return t;
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