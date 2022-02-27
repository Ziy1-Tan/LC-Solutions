// 回溯+set去重，当全部字符遍历后，将结果加入集合，否则选一个之前没遍历到的字符加入结果集
// 时间复杂度O(NxN!) 每次遍历都需要遍历一边字符串,然后一共有N!种全排列
// 空间复杂度O(N!) 最差情况下，保存字符串需要N!空间
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  vector<string> permutation(string s) {
    n = s.size();
    if (n == 0)
      return vector<string>(res.begin(), res.end());

    dfs(0, s);

    return vector<string>(res.begin(), res.end());
  }

private:
  int n;
  string tmp;
  unordered_set<string> res;
  void dfs(int k, string &s) {
    if (k == n) {
      res.insert(tmp);
      return;
    }

    for (int i = 0; i < n; i++) {
      if (s[i] != '0') {
        char c = s[i];
        tmp.push_back(c);
        s[i] = '0';
        dfs(k + 1, s);
        tmp.pop_back();
        s[i] = c;
      }
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