#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 1; i <= n; i++) {
    nums[i - 1] = i;
  }
  long long sum = 0;
  do {
    long long cnt = 0;
    for (int i = 1; i < n; i++) {
      if (nums[i] % 2 == 1 && nums[i - 1] % 2 == 1) {
        cnt++;
      }
    }
    sum += cnt;
  } while (next_permutation(nums.begin(), nums.end()));

  cout << sum % ((int)pow(10, 9) + 7) << endl;

  return 0;
}
