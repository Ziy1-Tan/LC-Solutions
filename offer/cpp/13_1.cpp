// dfs深度遍历搜索，v来记录该格子是否访问过
// 终止条件：超过边界，不满足数位条件
// 时间复杂度O(MN)
// 空间复杂度O(MN)
#include <ios>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  int movingCount(int m, int n, int k) {
    this->m = m;
    this->n = n;
    this->k = k;
    vector<vector<bool>> v(m, vector<bool>(n, false));
    this->v = v;
    return dfs(0, 0);
  }

private:
  int m;
  int n;
  int k;
  vector<vector<bool>> v;
  int dfs(int i, int j) {
    if (i < 0 || i >= m || j < 0 || j >= n || check(i, j) || v[i][j])
      return 0;
    v[i][j] = true;
    int cnt = dfs(i - 1, j) + dfs(i + 1, j) + dfs(i, j - 1) + dfs(i, j + 1);
    return 1 + cnt;
  }

  bool check(int i, int j) {
    string tmp = to_string(i) + to_string(j);
    int sum = 0;
    for (const auto &c : tmp) {
      int d = c - '0';
      sum += d;
    }
    return sum > k;
  }
};

int main(int argc, const char *argv[]) {
  Solution s;
  auto res = s.movingCount(3, 1, 0);
  cout << res << endl;
  return 0;
}