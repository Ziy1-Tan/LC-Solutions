/**
    小红拿到了一棵树，每个节点被染成了红色或者蓝色。
    小红定义每条边的权值为：删除这条边时，形成的两个子树的同色连通块数量之差的绝对值。
    小红想知道，所有边的权值之和是多少？

    输入描述
    第一行输入一个正整数 n ,代表节点的数量。
    第二行输入一个长度为 n 且仅由 R 和 B 两种字符组成的字符串。
    第 i 个字符为 R 代表 i 号节点被染成红色，为 B 则被染成蓝色。
    接下来的 n−1 行，每行输入两个正整数 u 和 v ，代表节点 u 和节点 v
   有一条边相连。 1≤n≤200000
*/
#include <iostream>
#include <string>
#include <vector>

using i64 = long long;

int main() {
  int n;
  std::string s;
  std::cin >> n >> s;
  std::vector adj(n, std::vector<int>());
  std::vector<int> dp(n, 1);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    std::cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  i64 ans = 0;
  std::function<void(int, int)> dfs = [&](int x, int fa) {
    for (auto y : adj[x]) {
      if (y == fa) continue;
      dfs(y, x);
      if (s[x] != s[y]) {
        dp[x] += dp[y];
      } else {
        dp[x] += dp[y] - 1;
      }
    }
  };

  std::function<void(int, int)> calc = [&](int x, int fa) {
    for (auto y : adj[x]) {
      if (y == fa) continue;
      calc(y, x);
      if (s[x] == s[y]) {
        ans += std::abs(dp[0] - dp[y] + 1 - dp[y]);
      } else {
        ans += std::abs(dp[0] - dp[y] - dp[y]);
      }
    }
  };

  dfs(0, -1);
  calc(0, -1);
  std::cout << ans << "\n";

  return 0;
}
