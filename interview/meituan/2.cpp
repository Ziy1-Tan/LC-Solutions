#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int solve(const vector<int>& nums, int n, int k) {
  unordered_map<int, int> map;
  int ans = 0;
  int l = 0, r = 0, cnt = 0;
  while (r < n) {
    int c = nums[r];
    map[c]++;
    if (map[c] == 1) {
      cnt++;
    }

    while (cnt > k) {
      int c2 = nums[l];
      map[c2]--;
      if (map[c2] == 0) {
        cnt--;
      }
      l++;
    }

    ans = max(ans, r - l + 1);
    r++;
  }

  return ans;
}
int main() {
  int n = 8, k = 3;
  cin >> n >> k;
  vector<int> nums{};
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    nums.push_back(a);
  }
  cout << solve(nums, n, k) << endl;
  return 0;
}
