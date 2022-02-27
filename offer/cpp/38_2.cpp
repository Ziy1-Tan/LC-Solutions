// 回溯+排序去重，如果s中存在重复字符，则会产生重复全排列
// 填每一个空位的时候重复字符只会被填入一次，所以要对s进行排序，使得重复字符相邻
// 当相邻字符相同且前一个字符被访问过的时候，说明当前字符不需要填入
// 反之则填入
// 时间复杂度O(NxN!) 每次遍历都需要遍历一边字符串,然后一共有N!种全排列
// 空间复杂度O(N!) 最差情况下，保存字符串需要N!空间
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  vector<string> permutation(string s) {
    n = s.size();
    if (n == 0)
      return res;

    sort(s.begin(), s.end());
    used.assign(n, false);
    dfs(0, s);

    return res;
  }

private:
  int n;
  string tmp;
  vector<string> res;
  vector<bool> used;
  void dfs(int k, string &s) {
    if (k == n) {
      res.push_back(tmp);
      return;
    }

    for (int i = 0; i < n; i++) {
      // 相邻重复字符且该字符已经被使用过
      if (used[i] || (i > 0 && s[i] == s[i - 1] && !used[i - 1]))
        continue;

      // 回溯
      used[i] = true;
      tmp.push_back(s[i]);
      dfs(k + 1, s);
      tmp.pop_back();
      used[i] = false;
    }
  }
};

int main(int argc, const char *argv[]) {
  Solution s;
  string str = "aab";
  auto res = s.permutation(str);
  for (auto &e : res) {
    cout << e << endl;
  }
  return 0;
}