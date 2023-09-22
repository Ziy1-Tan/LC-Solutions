#include <array>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> findAnagrams(string s, string p) {
    vector<int> c1(26);
    vector<int> c2(26);
    vector<int> res;
    int n = s.size(), m = p.size();
    for (int i = 0; i < m; i++) {
      c1[p[i] - 'a']++;
    }

    for (int l = 0, r = 0; r < n; r++) {
      c2[s[r] - 'a']++;
      if (r - l + 1 > m) {
        c2[s[l] - 'a']--;
        l++;
      }
      if (equal(c1.cbegin(), c1.cend(), c2.cbegin())) {
        res.push_back(l);
      }
    }

    return res;
  }
};

// a为p中不同字符的数量，b为窗口内不同字符的数量
class Solution2 {
 public:
  vector<int> findAnagrams(string s, string p) {
    vector<int> res;
    vector<int> cnt(26);
    int n = s.size(), m = p.size();
    for (int i = 0; i < m; i++) {
      cnt[p[i] - 'a']++;
    }
    int a = 0;
    for (int i = 0; i < 26; i++) {
      if (cnt[i]) {
        a++;
      }
    }

    for (int l = 0, r = 0, b = 0; r < n; r++) {
      if (--cnt[s[r] - 'a'] == 0) {
        b++;
      }
      if (r - l + 1 > m && ++cnt[s[l++] - 'a'] == 1) {
        b--;
      }
      if (a == b) {
        res.push_back(l);
      }
    }

    return res;
  }
};

int main(int argc, char const *argv[]) {
  string s = "cbaebabacd", p = "abc";
  auto res = (new Solution2)->findAnagrams(s, p);
  auto pv = [](const auto res) {
    for (auto &&i : res) cout << i << " ";
    cout << '\n';
  };
  pv(res);
  return 0;
}
