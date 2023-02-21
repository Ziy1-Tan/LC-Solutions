#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int slow = 0;
    int maxLen = 0;
    unordered_set<char> set;
    for (int fast = 0; fast < s.size(); fast++) {
      while (set.count(s[fast])) {
        set.erase(s[slow++]);
      }
      maxLen = max(maxLen, fast - slow + 1);
      set.insert(s[fast]);
    }
    return maxLen;
  }
};

int main(int argc, const char *argv[]) {
  cout << (new Solution)->lengthOfLongestSubstring("s11111s") << endl;
  return 0;
}
