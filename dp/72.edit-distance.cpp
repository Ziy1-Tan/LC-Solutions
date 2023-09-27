#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  int minDistance(string word1, string word2) {
    int n = word1.size(), m = word2.size();
    if (n == 0 && m == 0) {
      return 0;
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; i++) {
      dp[i][0] = i;
    }

    for (int i = 0; i <= m; i++) {
      dp[0][i] = i;
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        // 增删改
        dp[i][j] = min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]}) + 1;
        if (word1[i - 1] == word2[j - 1]) {
          dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
        }
      }
    }

    return dp.back().back();
  }
};

int main(int argc, char const *argv[]) {
  string word1{"horse"};
  string word2{"ros"};
  cout << (new Solution)->minDistance(word1, word2) << endl;
  return 0;
}
