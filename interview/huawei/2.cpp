#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int m, n;
vector<vector<int>> nums;
vector<vector<int>> visited;
int res = INT32_MAX;

void dfs(int i, int j, int curr) {
  if (i < 0 || i >= m || j < 0 || j >= n) {
    return;
  }

  if (nums[i][j] == 0 || visited[i][j]) {
    return;
  }

  if (j == n - 1) {
    if (nums[i][j] == 1) {
      res = min(res, curr + 1);
    }
    return;
  }

  visited[i][j] = 1;

  dfs(i + 1, j, curr + 1);
  dfs(i - 1, j, curr + 1);
  dfs(i, j - 1, curr + 1);
  dfs(i, j + 1, curr + 1);
}

int main(int argc, char const *argv[]) {
  cin >> m >> n;
  nums.assign(m, vector<int>(n));
  visited.assign(m, vector<int>(n));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> nums[i][j];
    }
  }

  for (int i = 0; i < m; i++) {
    if (nums[i][0] == 1) {
      dfs(i, 0, 0);
      visited.assign(m, vector<int>(n));
    }
  }

  if (res == INT32_MAX) {
    cout << -1 << endl;
  } else {
    cout << res - 1 << endl;
  }

  return 0;
}
