// 截取前半部分，将后半部分前移动，然后后半部分前移，最后拼接前半部分
// 时间O(S)
// 空间O(N)
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
  string reverseLeftWords(string s, int n) {
    if (n >= s.size()) {
      return s;
    }
    // 前半部分
    string prev = s.substr(0, n);
    // 前移
    int i;
    for (i = n; i < s.size(); i++) {
      s[i - n] = s[i];
    }
    // 前半部分拼接上
    for (int j = i - n, k = 0; j < s.size() && k < prev.size(); j++, k++) {
      s[j] = prev[k];
    }

    return s;
  }
};

int main(int argc, const char *argv[]) {
  auto res = Solution().reverseLeftWords("abcdefg", 7);
  cout << res << endl;
  return 0;
}