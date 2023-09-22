/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> map;
    for (auto&& s : strs) {
      string tmp = s;
      sort(tmp.begin(), tmp.end());
      map[tmp].push_back(s);
    }

    vector<vector<string>> res;
    for (auto&& [k, v] : map) {
      res.push_back(v);
    }
    return res;
  }
};

class Solution2 {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> res;
    unordered_map<string, int> map;
    int sub = 0;
    for (auto&& s : strs) {
      string tmp = s;
      sort(tmp.begin(), tmp.end());
      if (map.count(tmp)) {
        res[map[tmp]].push_back(s);
      } else {
        res.emplace_back(1, s);
        map[tmp] = sub++;
      }
    }

    return res;
  }
};
// @lc code=end
