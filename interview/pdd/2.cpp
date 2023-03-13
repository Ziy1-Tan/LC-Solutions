#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// BFS爆内存，贪心即可
int solve(const vector<int>& nums) {
  int cnt = count(nums.begin(), nums.end(), 1);
  int A = cnt % 2 ? cnt / 2 + 1 : cnt / 2;
  int B = nums.size() - cnt;
  return A + B;
}

int main() {
  int m = 3, n = 3;
  vector<vector<int>> games{
      {1, 2, 1, 1},
      {1, 2, 3, 3},
      {2, 3, 2, 1},
  };
  for (auto&& nums : games) {
    cout << solve(nums) << endl;
  }

  return 0;
}
