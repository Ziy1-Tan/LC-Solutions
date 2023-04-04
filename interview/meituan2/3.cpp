#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
  int n, m;
  cin >> n >> m;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    nums[i] = num;
  }

  sort(nums.begin(), nums.end());
  for (int i = 0; i < m; i++) {
    int sum;
    cin >> sum;
    int cnt = 0;
    for (auto &&num : nums) {
      if (num <= sum / num) {
        cnt++;
        sum -= num * num;
        if (sum <= 0) {
          break;
        }
      }
    }
    cout << cnt << (i == m - 1 ? "" : " ");
  }
  return 0;
}
