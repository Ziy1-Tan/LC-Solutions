#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    nums[i] = num;
  }
  vector<int> dp(n);
  dp[0] = nums[0];
  dp[1] = nums[0] > nums[1] ? nums[0] : nums[1];
  dp[2] = max({nums[0], nums[1], nums[2]});
  for (int i = 3; i < n; i++) {
    dp[i] = max(dp[i - 1], dp[i - 3] + nums[i]);
  }

  cout << dp.back() << endl;

  return 0;
}
