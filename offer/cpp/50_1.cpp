#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  char firstUniqChar(string s) {
    vector<int> dict(26, 0);
    for (const auto c : s) {
      dict[c - 'a']++;
    }

    for (const auto c : s) {
      if (dict[c - 'a'] == 1)
        return c;
    }

    return ' ';
  }
};