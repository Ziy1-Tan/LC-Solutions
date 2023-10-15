#include <iostream>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> map;
    for (auto&& i : nums) {
      map[i]++;
    }

    auto cmp = [](const pair<int, int>& p1, const pair<int, int>& p2) {
      return p1.second < p2.second;
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(
        cmp);
    for (auto&& i : map) {
      q.push(i);
    }

    vector<int> res;
    for (int i = 0; i < k; i++) {
      res.push_back(q.top().first);
      q.pop();
    }
    return res;
  }
};
class Solution2 {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> map;
    for (const auto& num : nums) {
      map[num]++;
    }

    auto cmp = [](pair<int, int>& p1, pair<int, int>& p2) {
      return p1.second > p2.second;
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(
        cmp);

    for (const auto& p : map) {
      if (q.size() < k) {
        q.push(p);
      } else if (q.size() >= k && p.second > q.top().second) {
        q.pop();
        q.push(p);
      }
    }

    vector<int> res;
    for (int i = 0; i < k; i++) {
      res.push_back(q.top().first);
      q.pop();
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  vector<int> nums{3, 0, 1, 0};
  auto res = (new Solution2)->topKFrequent(nums, 1);
  [](const auto res) {
    for (auto&& i : res) cout << i << " ";
    cout << '\n';
  }(res);
  return 0;
}
