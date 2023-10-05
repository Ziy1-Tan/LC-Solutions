#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    int len = s.size();
    vector<bool> dp(len + 1, false);
    unordered_set<string> wordSet;
    for (auto&& word : wordDict) {
      wordSet.insert(word);
    }
    dp[0] = true;
    /*
     * @param i: 长度为l的前缀子串
     * @param j: 用于遍历前缀子串是否可以被拆分
     */
    for (int i = 1; i <= len; i++) {
      for (int j = 0; j < i; j++) {
        if (dp[j] && wordSet.count(s.substr(j, i - j))) {
          dp[i] = true;
          break;
        }
      }
    }
    return dp[len];
  }
};

int main(int argc, char const* argv[]) {
  vector<string> words{"leet", "code"};
  string s = "leetcode";
  cout << boolalpha;
  cout << (new Solution)->wordBreak(s, words) << endl;
  return 0;
}
