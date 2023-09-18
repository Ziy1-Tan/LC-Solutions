#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    if (coins.empty() || amount == 0) {
      return 0;
    }
    std::vector<std::vector<int>> dp(coins.size(),
                                     vector<int>(amount + 1, amount + 1));
    for (int j = 0; j <= amount; j++) {
      if (j % coins[0] == 0) {
        dp[0][j] = j / coins[0];
      }
    }
    for (int i = 0; i < coins.size(); i++) {
      dp[i][0] = 0;
    }

    // dp[i][j] = min(dp[i-1][j], dp[i][j-coins[i]]+1)
    for (int i = 1; i < coins.size(); i++) {
      for (int j = 1; j <= amount; j++) {
        if (j < coins[i]) {
          dp[i][j] = dp[i - 1][j];
        } else {
          dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i]] + 1);
        }
      }
    }
    int ans = dp.back().back();
    return ans == amount + 1 ? -1 : ans;
  }
};

int main(int argc, char const* argv[]) {
  vector<int> coins = {2, 5, 10, 1};
  cout << (new Solution())->coinChange(coins, 27) << endl;
  return 0;
}
