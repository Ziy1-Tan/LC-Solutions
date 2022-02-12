// 在n无限制时，使用pow+for循环的方式会导致溢出
// 需要使用dfs生成n位0-9的全排列
// 时间复杂度O(10^N)
// 空间复杂度O(10^N)
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> printNumbers(int n) {
    vector<int> res_int;
    for (int i = 1; i <= n; i++) // 数字长度：1~n
      dfs(0, i);
    for (const auto &s : this->res) {
      res_int.push_back(stoi(s));
    }
    return res_int;
  }

private:
  const int NUMS[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
  vector<string> res; //保存结果
  string cur;         //目前生成的字符串
  void dfs(int index, int len) {
    //当所有位都列举完毕，则加入结果
    if (index == len) {
      res.push_back(cur);
      return;
    }

    //去掉最高位的'0'
    int start = index == 0 ? 1 : 0;
    for (int i = start; i < 10; i++) {
      // 当前位设置为0-9不同的数字
      cur.push_back(NUMS[i]);
      // 继续设置下一位
      dfs(index + 1, len);
      // 撤销设置的数字，设置另一个数字
      cur.pop_back();
    }
  }
};

int main(int argc, const char *argv[]) {
  auto res = (new Solution())->printNumbers(2);
  for (auto e : res) {
    cout << e << endl;
  }
  return 0;
}