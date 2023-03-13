#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// 暴力80%用例过，参考数据流中的中位数
int main() {
  int n = 5;
  cin >> n;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    v.push_back(tmp);
  }
// [1,2,3,4,10]
// [1,2,2,3,4]
// [1,2,2,3,3]
  vector<int> ans1;
  vector<int> ans2;
  double sum = 0;
  for (int i = 0; i < n; i++) {
    sum += v[i];
    ans1.push_back(round(sum / (i + 1)));
    sort(v.begin(), v.begin() + i + 1);
    ans2.push_back(i % 2 == 0 ? v[i / 2]
                              : round((double)(v[i / 2] + v[i / 2 + 1]) / 2));
  }

  for (size_t i = 0; i < n; i++) {
    cout << ans1[i] << (i == n - 1 ? "\n" : " ");
  }
  for (size_t i = 0; i < n; i++) {
    cout << ans2[i] << (i == n - 1 ? "\n" : " ");
  }

  return 0;
}
