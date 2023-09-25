#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.size() < 2) {
      return intervals;
    }

    sort(intervals.begin(), intervals.end());

    int n = intervals.size();
    vector<vector<int>> ans;
    for (const auto& interval : intervals) {
      int l = interval[0], r = interval[1];
      if (ans.empty() || ans.back()[1] < l) {
        ans.push_back({l, r});
      } else {
        ans.back()[1] = max(ans.back()[1], r);
      }
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) {
  vector<vector<int>> intervals{{1, 8}, {3, 6}};
  auto ans = (new Solution)->merge(intervals);
  auto pv = [](const auto res) {
    for (auto&& i : res) cout << i << " ";
    cout << '\n';
  };
  for (auto&& i : ans) {
    pv(i);
  }

  return 0;
}
