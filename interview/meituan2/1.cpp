#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool solve(const vector<int>& in, const vector<int>& out) {
  stack<int> s;
  int idx = 0;
  for (auto&& x : in) {
    s.push(x);
    while (!s.empty() && s.top() == out[idx]) {
      s.pop();
      idx++;
    }
  }
  return s.empty() && idx == out.size();
}

int main(int argc, char const* argv[]) {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    vector<int> in(n);
    vector<int> out(n);
    for (int i = 0; i < n; i++) {
      int num;
      cin >> num;
      in[i] = num;
    }
    for (int i = 0; i < n; i++) {
      int num;
      cin >> num;
      out[i] = num;
    }
    if (solve(in, out)) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }

  return 0;
}
