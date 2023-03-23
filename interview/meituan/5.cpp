#include <array>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

constexpr static int N = 500;
static vector<int> dist(N);
static vector<int> sum(N);
static vector<vector<int>> arr(N);

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    dist[i] = num;
  }

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    arr[u].push_back(v);
    arr[v].push_back(u);
  }

  function<void(int, int, int)> dfs = [&](int i, int fa, int d) {
    if (d < 0) {
      return;
    }
    sum[i]++;
    for (auto &&j : arr[i]) {
      if (j == fa) {
        continue;
      }
      dfs(j, i, d - 1);
    }
  };

  for (int i = 0; i < n; i++) {
    dfs(i, -1, dist[i]);
  }

  for (int i = 0; i < n; i++) {
    cout << sum[i] << " ";
  }
  return 0;
}
