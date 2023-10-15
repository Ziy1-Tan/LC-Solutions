#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    dfs(candidates, target, 0);
    return res;
  }

 private:
  vector<vector<int>> res;
  vector<int> path;
  void dfs(const vector<int> &candidates, int rest, int idx) {
    if (rest == 0) {
      res.push_back(path);
      return;
    }

    for (int i = idx; i < candidates.size(); i++) {
      // 同层不重复，同路径可以重复
      if (i > idx && candidates[i] == candidates[i - 1]) continue;
      if (rest - candidates[i] >= 0) {
        path.push_back(candidates[i]);
        dfs(candidates, rest - candidates[i], i + 1);
        path.pop_back();
      }
    }
  }
};

int main(int argc, char const *argv[]) {
  vector<int> v = {10, 1, 2, 7, 6, 1, 5};
  auto res = (new Solution)->combinationSum2(v, 8);
  auto pv = [](const auto &res) {
    for (auto &&i : res) cout << i << " ";
    cout << '\n';
  };
  for (auto &&v : res) pv(v);

  return 0;
}
