// 分别截取字符串的前半部分和后半部分
// 结果等于后半+前半
// 时间O(S)
// 空间O(S)
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
  string reverseLeftWords(string s, int n) {
    if (n > s.size()) {
      return s;
    }
    // 分别截取前半部分和后半部分
    string prev = s.substr(0, n);
    string next = s.substr(n);

    return next + prev;
  }
};

int main(int argc, const char *argv[]) {
  auto res = Solution().reverseLeftWords("abcdefg", 1);
  cout << res << endl;
  return 0;
}