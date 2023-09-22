/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isAnagram(string s, string t) {
    if (s.size() != t.size()) {
      return false;
    }
    vector<int> cnt1(26);
    vector<int> cnt2(26);
    for (auto &&i : s) {
      cnt1[i - 'a']++;
    }

    for (auto &&i : t) {
      cnt2[i - 'a']++;
    }

    return equal(cnt1.begin(), cnt1.end(), cnt2.begin());
  }
};

class Solution2 {
 public:
  bool isAnagram(string s, string t) {
    if (s.size() != t.size()) {
      return false;
    }
    vector<int> cnt(26);
    for (int i = 0; i < s.size(); i++) {
      cnt[s[i] - 'a']++;
      cnt[t[i] - 'a']--;
    }
    return std::all_of(cnt.begin(), cnt.end(), [](int i) { return i == 0; });
  }
};

int main(int argc, char const *argv[]) {
  cout << (new Solution2)->isAnagram("1", "1") << endl;
  return 0;
}

// @lc code=end
