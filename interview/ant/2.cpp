#include <functional>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  string color;
  cin >> n >> color;
  vector<vector<int>> d(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    d[u].push_back(v);
    d[v].push_back(u);
  }

  vector<int> visited(n);
  int cnt = 0;
  function<void(int, int)> dfs = [&](int i, char co) {
    if (visited[i]) {
      return;
    }
    visited[i] = 1;
    char prev = color[i];
    if (color[i] == co) {
      color[i] = (co == 'R') ? 'W' : 'R';
      cnt++;
    }

    for (auto &&ch : d[i]) {
      dfs(ch, color[i]);
    }
    color[i] = prev;
  };

  dfs(0, 'W');
  int prev = cnt;
  dfs(0, 'R');

  cout << min(cnt, prev) << endl;
  return 0;
}
