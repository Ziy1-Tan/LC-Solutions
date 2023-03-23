#include <iostream>
#include <vector>
using namespace std;
const int N = 1001;

int main() {
  vector<vector<int>> s(N, vector(N, 0));
  int n = 3, a = 1, b = 1;
  a++, b++;
  // cin >> n >> a >> b;
  // for (int i = 0; i < n; i++) {
  //   int x, y;
  //   cin >> x >> y;
  //   s[x][y]++;
  // }
  s[1][1] = s[1][2] = s[1][3] = 1;

  for (int i = 1; i < N; i++) {
    for (int j = 1; j < N; j++) {
      s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
    }
  }

  int ans = 0;
  for (int i = a; i < N; i++) {
    for (int j = b; j < N; j++) {
      ans = max(ans, s[i][j] - s[i - a][j] - s[i][j - b] + s[i - a][j - b]);
    }
  }

  cout << ans << endl;
  return 0;
}
