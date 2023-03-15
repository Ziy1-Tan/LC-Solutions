#include <array>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
 private:
  constexpr static array dx = {0, 1, 0, -1};
  constexpr static array dy = {1, 0, -1, 0};

 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    int m = matrix.size(), n = matrix[0].size();
    int l = 0, r = n - 1, u = 0, b = m - 1;
    int d = 0;
    int x = 0, y = -1;
    while (ans.size() < m * n) {
      for (int i = l; i <= r; i++) {
        x = x + dx[d];
        y = y + dy[d];
        ans.push_back(matrix[x][y]);
      }
      u++;
      d = (d + 1) % 4;
      for (int i = u; i <= b; i++) {
        x = x + dx[d];
        y = y + dy[d];
        ans.push_back(matrix[x][y]);
      }
      r--;
      d = (d + 1) % 4;
      for (int i = l; i <= r; i++) {
        x = x + dx[d];
        y = y + dy[d];
        ans.push_back(matrix[x][y]);
      }
      b--;
      d = (d + 1) % 4;
      for (int i = u; i <= b; i++) {
        x = x + dx[d];
        y = y + dy[d];
        ans.push_back(matrix[x][y]);
      }
      l++;
      d = (d + 1) % 4;
    }
    ans.resize(m * n);
    return ans;
  }
};

class Solution2 {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    int m = matrix.size(), n = matrix[0].size();
    int l = 0, r = n - 1, u = 0, b = m - 1;
    while (true) {
      for (int i = l; i <= r; i++) ans.push_back(matrix[u][i]);
      if (++u > b) break;
      for (int i = u; i <= b; i++) ans.push_back(matrix[i][r]);
      if (l > --r) break;
      for (int i = r; i >= l; i--) ans.push_back(matrix[b][i]);
      if (u > --b) break;
      for (int i = b; i >= u; i--) ans.push_back(matrix[i][l]);
      if (++l > r) break;
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) {
  vector<vector<int>> v{
    {1, 2, 3, 4}, 
    {5, 6, 7, 8},
    {9, 10, 11, 12}
  };
  auto ans = (new Solution2)->spiralOrder(v);
  auto pv = [](const auto res) {
    for (auto&& i : res) cout << i << " ";
    cout << '\n';
  };
  pv(ans);
  return 0;
}
