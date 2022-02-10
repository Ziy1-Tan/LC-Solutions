// 广度优先遍历，利用队列实现
// 队头元素出列，格子数加一后将右方下方元素入队
// 时间复杂度O(MN)
// 空间复杂度O(MN)
#include <ios>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;
class Solution {
public:
  int movingCount(int m, int n, int k) {
    int cnt = 0;
    vector<vector<bool>> v(m, vector<bool>(n, false));

    queue<tuple<int, int>> q;
    q.push({0, 0});
    while (!q.empty()) {
      auto t = q.front();
      q.pop();
      int i = get<0>(t), j = get<1>(t);
      if (i < 0 || i >= m || j < 0 || j >= n || v[i][j] ||
          (sum(i) + sum(j)) > k)
        continue;
      v[i][j] = true;
      cnt++;
      q.push({i + 1, j});
      q.push({i, j + 1});
    }

    return cnt;
  }

private:
  int sum(int x) {
    int sum = 0;
    while (x != 0) {
      sum += x % 10;
      x /= 10;
    }
    return sum;
  }
};

int main(int argc, const char *argv[]) {
  Solution s;
  auto res = s.movingCount(2, 3, 1);
  cout << res << endl;
  return 0;
}