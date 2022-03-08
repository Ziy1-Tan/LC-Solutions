// 局部反转+整体反转
// 首先分别反转[0,n),[n,size)部分的字符，然后整体反转
// 时间 O(N)
// 空间 O(1)
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
  string reverseLeftWords(string s, int n) {
    if (n >= s.size()) {
      return s;
    }

    reverse(s.begin(), s.begin() + n);
    reverse(s.begin() + n, s.end());
    reverse(s.begin(), s.end());

    return s;
  }
};

int main(int argc, const char *argv[]) {
  auto res = Solution().reverseLeftWords("abcdefg", 2);
  cout << res << endl;
  return 0;
}