#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int maxLen = 0;
    int n = s.size();
    int l = 0, r = 0;
    unordered_set<char> set;
    while (r < n) {
      while (set.count(s[r])) {
        set.erase(s[l++]);
      }
      maxLen = max(maxLen, r - l + 1);
      set.insert(s[r++]);
    }
    return maxLen;
  }
};

int main(int argc, const char *argv[]) {
  cout << (new Solution)->lengthOfLongestSubstring("s11111s") << endl;
  return 0;
}
