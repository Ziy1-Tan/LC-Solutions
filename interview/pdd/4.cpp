#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// 暴力80%用例过，参考数据流中的中位数
int main() {
  int n = 5;
  vector<int> v = {1, 2, 3, 4, 10};
  // int n;
  // vector<int> v;
  // cin >> n;
  // for (int i = 0; i < n; i++) {
  //   int tmp;
  //   cin >> tmp;
  //   v.push_back(tmp);
  // }

  // [1,2,3,4,10]
  // [1,2,2,3,4]
  // [1,2,2,3,3]
  vector<int> avg;
  vector<int> mid;
  priority_queue<int, vector<int>, less<int>> l;
  priority_queue<int, vector<int>, greater<int>> r;
  double sum = 0;
  for (int i = 0; i < v.size(); i++) {
    sum += v[i];
    avg.push_back(round(sum / (i + 1)));
    if (l.size() == r.size()) {
      if (l.empty() || v[i] <= r.top()) {
        l.push(v[i]);
      } else {
        l.push(r.top());
        r.pop();
        r.push(v[i]);
      }
      mid.push_back(l.top());
    } else {
      if (v[i] >= l.top()) {
        r.push(v[i]);
      } else {
        r.push(l.top());
        l.pop();
        l.push(v[i]);
      }
      mid.push_back(round(((double)(l.top() + r.top())) / 2.0));
    }
  }

  for (auto &&i : avg) {
    cout << i << " ";
  }
  cout << '\n';

  for (auto &&i : mid) {
    cout << i << " ";
  }

  return 0;
}
