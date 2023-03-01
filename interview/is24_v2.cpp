#include <cmath>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

const int target = 24;
const double esp = 1e-6;
const char ops[4] = {'+', '*', '-', '/'};
unordered_set<string> ans;

void combine(vector<double> &nums, vector<string> &exprs) {
  if (nums.size() == 0) {
    return;
  }

  if (nums.size() == 1) {
    if (fabs(nums[0] - target) < esp) {
      ans.insert(exprs[0]);
      return;
    }
  }

  // 任选两个数
  int n = nums.size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) {
        continue;
      }
      vector<double> newNums;
      vector<string> newExprs;
      // 未选到的数加入到下一层的迭代
      for (int k = 0; k < n; k++) {
        if (k != i && k != j) {
          newNums.push_back(nums[k]);
          newExprs.push_back(exprs[k]);
        }
      }

      for (int k = 0; k < 4; k++) {
        // 对于乘法和加法，满足交换律，跳过
        if (k < 2 && i > j) {
          continue;
        }

        // 挑到的两个数做运算组合
        char op = ops[k];
        if (op == '+') {
          newNums.push_back(nums[i] + nums[j]);
        } else if (op == '*') {
          newNums.push_back(nums[i] * nums[j]);
        } else if (op == '-') {
          newNums.push_back(nums[i] - nums[j]);
        } else if (op == '/') {
          if (fabs(nums[j]) < esp) {
            continue;
          }
          newNums.push_back(nums[i] / nums[j]);
        }
        newExprs.push_back("(" + exprs[i] + op + exprs[j] + ")");
        combine(newNums, newExprs);
        newNums.pop_back();
        newExprs.pop_back();
      }
    }
  }
}

int main(int argc, char const *argv[]) {
  vector<vector<int>> cases{
      {6, 6, 6, 6},
      {3, 8, 6, 4}, 
      {3, 1, 6, 4},
      {13, 9, 12, 12}
  };
  for (const auto &c : cases) {
    ans.clear();
    vector<double> nums(c.begin(), c.end());
    vector<string> exprs;
    for (auto &&num : c) {
      exprs.push_back(to_string(num));
    }

    combine(nums, exprs);
    for (auto &&expr : ans) {
      cout << expr << '\n';
    }
    cout << "------------------------" << '\n';
  }

  return 0;
}
