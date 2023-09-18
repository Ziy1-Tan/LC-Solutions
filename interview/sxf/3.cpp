#include <iostream>
#include <vector>
using namespace std;

int m, n;
vector<vector<int>> grid;
vector<vector<bool>> visited;
int max_value;

void dfs(int i, int j, int current_value) {
  if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j]) {
    return;
  }

  if (grid[i][j] == -1) {
    grid[i][j] = 0;
    visited[i][j] = true;
  } else {
    current_value += grid[i][j];
    max_value = max(max_value, current_value);
    visited[i][j] = true;
  }

  dfs(i - 1, j, current_value);  // 上方
  dfs(i + 1, j, current_value);  // 下方
  dfs(i, j - 1, current_value);  // 左方
  dfs(i, j + 1, current_value);  // 右方

  visited[i][j] = false;
  if (grid[i][j] == 0) {
    grid[i][j] = -1;
  }
}

int max_collect_value(vector<vector<int>>& input_grid) {
  grid = input_grid;
  m = grid.size();
  n = grid[0].size();

  visited = vector<vector<bool>>(m, vector<bool>(n, false));
  max_value = 0;

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j] == -1) {
        grid[i][j] = 0;
        dfs(0, 0, 0);
        grid[i][j] = -1;
      }
    }
  }

  return max_value;
}

int main() {
  cin >> n >> m;
  grid.assign(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
    }
  }
  grid.assign(n, vector<int>(m));

  int max_value = max_collect_value(grid);
  cout << max_value << endl;  // 输出 21

  return 0;
}
