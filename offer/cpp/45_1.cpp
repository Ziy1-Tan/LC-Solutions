// 升序序列最小，拼接起来以后升序排列，排序规则 x+y <
// y+x，比较字符串拼接后生成的字符串哪个比较小 时间复杂度 O(NlongN) 空间复杂度
// O(N)
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  string minNumber(vector<int> &nums) {
    vector<string> strs(nums.size());
    for (int i = 0; i < nums.size(); i++) {
      strs[i] = to_string(nums[i]);
    }

    sort(strs.begin(), strs.end(), compare);

    string res("");
    res = accumulate(strs.begin(), strs.end(), res);

    return res;
  }

private:
  static bool compare(string &x, string &y) { return x + y < y + x; }
};

int main(int argc, const char *argv[]) {
  vector<int> nums{3, 30, 34, 5, 9};
  cout << (new Solution())->minNumber(nums) << endl;
  return 0;
}