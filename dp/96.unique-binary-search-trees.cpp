#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  int numTrees(int n) {
    if (n == 1) {
      return 1;
    }
    if (n == 2) {
      return 2;
    }
    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
      for (int j = 1; j <= i; j++) {
        dp[i] += dp[j - 1] * dp[i - j];
      }
    }

    return dp[n];
  }
};

int main(int argc, char const *argv[]) {
  cout << (new Solution)->numTrees(3) << endl;
  return 0;
}
