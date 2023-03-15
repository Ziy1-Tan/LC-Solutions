#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    if (n < 2) {
      return n;
    }
    vector<int> dp(n, 1);
    int ans = 1;
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (nums[j] < nums[i]) {
          dp[i] = max(dp[j] + 1, dp[i]);
        }
      }
      ans = max(ans, dp[i]);
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) {
  vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18};
  cout << (new Solution)->lengthOfLIS(nums) << endl;
  return 0;
}
