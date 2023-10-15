#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<vector<int>> permute(vector<int> &nums) {
    this->used.assign(nums.size(), 0);
    this->path.reserve(nums.size());
    dfs(nums);
    return res;
  }

 private:
  vector<vector<int>> res;
  vector<int> path;
  vector<int> used;
  void dfs(const vector<int> &nums) {
    if (path.size() == nums.size()) {
      res.push_back(path);
      return;
    }

    for (int i = 0; i < nums.size(); i++) {
      if (used[i]) continue;
      used[i] = 1;
      path.push_back(nums[i]);
      dfs(nums);
      path.pop_back();
      used[i] = 0;
    }
  }
};

int main(int argc, char const *argv[]) {
  vector<int> v = {1, 2, 3};
  auto res = (new Solution)->permute(v);
  auto pv = [](const auto res) {
    for (auto &&i : res) cout << i << " ";
    cout << '\n';
  };

  for (auto &&i : res) {
    pv(i);
  }

  return 0;
}
