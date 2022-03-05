// 双指针滑动窗口+hash表，指针i始终指向离j最近的与s[j]相等的字符
// hash表存储每个字符最后出现的位置
// 时间O(N)
// 空间(1) hash表只存储每个字符最后出现的位置 最多只需要存储O(128)个ASCII字符
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> dict;
    int i = -1, res = 0;
    for (int j = 0; j < s.size(); j++) {
      // 更新i,始终指向离j最近与s[j]相等字符
      if (dict.count(s[j]))
        i = max(i, dict[s[j]]);

      // 更新字符位置
      dict[s[j]] = j;

      // 更新最大值
      res = max(res, j - i);
    }
    return res;
  }
};

int main(int argc, const char *argv[]) {
  cout << Solution().lengthOfLongestSubstring("abcabcbb") << endl;
  return 0;
}