#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  int minDistance(string word1, string word2) {
    int m = word1.size(), n = word2.size();
    // word1的前i个字符和word2的前j个字符的编辑距离
    vector<vector<int>> dp(m + 1, vector(n + 1, 0));
    for (int i = 1; i <= m; i++) {
      dp[i][0] = i;
    }

    for (int i = 1; i <= n; i++) {
      dp[0][i] = i;
    }

    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        // 增删改
        dp[i][j] = min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]}) + 1;
        if (word1[i - 1] == word2[j - 1]) {
          dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
        }
      }
    }
    return dp[m][n];
  }
};

int main(int argc, char const *argv[]) {
  string word1{"horse"};
  string word2{"ros"};
  cout << (new Solution)->minDistance(word1, word2) << endl;
  return 0;
}
