// 利用next_permutation函数，生成下一个排列
// 时间复杂度O(NxN!) 生成第一个排列需要O(NlogN),
// next_permutation需要O(N)时间复杂度, 共需要生成N!个全排列（最差）
// 空间复杂度O(1)
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  vector<string> permutation(string s) {
    vector<string> res;
    sort(s.begin(), s.end());
    do {
      res.push_back(s);
    } while (nextPermutation(s));

    next_permutation()
    return res;
  }

private:
  bool nextPermutation(string &s) {
    int i = s.size() - 2;
    // 寻找小数
    while (i >= 0 && s[i] >= s[i + 1])
      i--;

    if (i < 0)
      return false;

    int j = s.size() - 1;
    while (j >= 0 && s[i] >= s[j])
      j--;

    swap(s[i], s[j]);
    reverse(s.begin() + i + 1, s.end());

    return true;
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