#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    for (auto&& x : nums) {
      map[x] = x + 1;
    }

    int cnt = 0;
    for (auto&& x : nums) {
      int y = find(x + 1);
      cnt = max(cnt, y - x);
    }
    return cnt;
  }

 private:
  //  key=起始位置 value=终止位置
  unordered_map<int, int> map;
  int find(int x) { return map.count(x) ? map[x] = find(map[x]) : x; }
};

#include <unordered_set>

class Solution2 {
 public:
  int longestConsecutive(vector<int>& nums) {
    unordered_set<int> numSet(nums.begin(), nums.end());
    int cnt = 0;
    for (auto&& num : nums) {
      int cur = num;
      if (!numSet.count(cur - 1)) {
        while (numSet.count(cur + 1)) {
          cur++;
        }
        cnt = max(cnt, cur - num + 1);
      }
    }
    return cnt;
  }
};

int main(int argc, char const* argv[]) {
  std::vector<int> nums = {1, 2, 3, 7, 4};
  cout << (new Solution2)->longestConsecutive(nums) << endl;
  return 0;
}
