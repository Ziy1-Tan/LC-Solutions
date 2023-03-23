#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
  int N = 3, X = 5, Y = 1;
  //   cin >> N >> X >> Y;
  vector<pair<int, int>> prices{{4, 3}, {3, 1}, {6, 5}};
  //   for (int i = 0; i < N; i++) {
  //     int a, b;
  //     cin >> a >> b;
  //     prices.push_back({a, b});
  //   }

  vector<vector<vector<int>>> dp(N + 1, vector(X + 1, vector(Y + 1, 0)));
  vector<vector<vector<int>>> cost(N + 1, vector(X + 1, vector(Y + 1, 0)));

  for (int i = 1; i <= N; i++) {
    auto price = prices[i - 1];
    for (int j = 1; j <= X; j++) {
      for (int k = 0; k <= Y; k++) {
        // 不买
        dp[i][j][k] = dp[i - 1][j][k];
        cost[i][j][k] = cost[i - 1][j][k];
        // 直接买
        if (j >= price.first) {
          if (dp[i][j - price.first][k] + 1 > dp[i][j][k]) {
            dp[i][j][k] = dp[i][j - price.first][k] + 1;
            cost[i][j][k] = cost[i][j - price.first][k] + price.first;
          } else if (dp[i][j - price.first][k] + 1 == dp[i][j][k]) {
            cost[i][j][k] =
                min(cost[i][j][k], cost[i][j - price.first][k] + price.first);
          }
        }
        // 拿券买
        if (j >= price.second && k > 0) {
          if (dp[i][j - price.second][k - 1] + 1 > dp[i][j][k]) {
            dp[i][j][k] = dp[i][j - price.second][k - 1] + 1;
            cost[i][j][k] = cost[i][j - price.second][k - 1] + price.second;
          } else if (dp[i][j - price.second][k - 1] + 1 == dp[i][j][k]) {
            cost[i][j][k] = min(
                cost[i][j][k], cost[i][j - price.second][k - 1] + price.second);
          }
        }
      }
    }
  }

  int res = INT32_MAX;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= X; j++) {
      for (int k = 0; k <= Y; k++) {
        if (dp[i][j][k] == dp[N][X][Y]) {
          res = min(res, cost[i][j][k]);
        }
      }
    }
  }
  cout << dp[N][X][Y] << " " << res << endl;
  return 0;
}
