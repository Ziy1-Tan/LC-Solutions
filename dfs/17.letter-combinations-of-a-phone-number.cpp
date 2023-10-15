#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<string> letters{"",    "",    "abc",  "def", "ghi",
                         "jkl", "mno", "pqrs", "tuv", "wxyz"};
  vector<string> letterCombinations(string digits) {
    if (!digits.empty()) {
      dfs(digits, 0, "");
    }
    return res;
  }

  vector<string> res;
  void dfs(const string &digits, int i, string tmp) {
    if (i >= digits.size()) {
      res.push_back(tmp);
      return;
    }

    string ls = letters[digits[i] - '0'];
    for (char c : ls) {
      dfs(digits, i + 1, tmp + c);
    }
  }
};

int main(int argc, char const *argv[]) {
  auto s = "29";
  auto res = (new Solution)->letterCombinations(s);
  auto pv = [](const vector<string> res) {
    for (auto &&i : res) cout << i << " ";
    cout << '\n';
  };
  pv(res);
  return 0;
}
