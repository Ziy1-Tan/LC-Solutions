#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int maximalSquare(vector<vector<char>>& matrix) {
    if (matrix.empty()) {
      return 0;
    }
    int m = matrix.size(), n = matrix.front().size();
    int len = 0;
    vector<vector<int>> dp(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (matrix[i][j] == '1') {
          if (i == 0 || j == 0)
            dp[i][j] = 1;
          else {
            dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
          }
        }
        len = max(len, dp[i][j]);
      }
    }
    return len * len;
  }
};

int main(int argc, char const* argv[]) {
  vector<vector<char>> matrix = {
      {'0', '0', '0'},
      {'0', '0', '1'},
      {'0', '0', '0'},
  };
  cout << (new Solution)->maximalSquare(matrix) << endl;
  return 0;
}
