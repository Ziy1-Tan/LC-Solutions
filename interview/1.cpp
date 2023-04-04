#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.size() == 0) {
      return {};
    }
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> merged;
    for (int i = 0; i < intervals.size(); ++i) {
      int L = intervals[i][0], R = intervals[i][1];
      if (!merged.size() || merged.back()[1] < L) {
        merged.push_back({L, R});
      } else {
        merged.back()[1] = max(merged.back()[1], R);
      }
    }
    return merged;
  }
};

class Solution2 {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> res;
    if (intervals.size() == 0) {
      return res;
    }

    sort(intervals.begin(), intervals.end());
    int st = INT_MIN, ed = INT_MIN;
    for (int i = 0; i < intervals.size(); i++) {
      if (ed < intervals[i][0]) {
        if (ed != INT_MIN) {
          vector<int> tmp(2);
          tmp[0] = st;
          tmp[1] = ed;
          res.push_back(tmp);
        }
        st = intervals[i][0];
        ed = intervals[i][1];
      }
      ed = max(ed, intervals[i][1]);
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  vector<vector<int>> intervals{{1, 6}, {8, 10}, {15, 18}};
  auto res = (new Solution2)->merge(intervals);
  auto pv = [](const auto res) {
    for (auto&& i : res) cout << i << " ";
    cout << '\n';
  };
  for (auto&& i : res) {
    pv(i);
  }

  return 0;
}
