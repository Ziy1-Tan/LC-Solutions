#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

class Solution {
 public:
  string multiply(string num1, string num2) {
    string ans{"0"};
    int m = num1.size(), n = num2.size();
    for (int j = n - 1; j >= 0; j--) {
      string tmp(n - 1 - j, '0');
      int c2 = num2[j] - '0';
      int flag = 0;
      for (int i = m - 1; i >= 0; i--) {
        int c1 = num1[i] - '0';
        int product = c1 * c2 + flag;
        flag = product / 10;
        tmp.push_back(product % 10 + '0');
      }

      if (flag > 0) {
        tmp.push_back('0' + flag);
      }
      if (std::all_of(tmp.begin(), tmp.end(),
                      [](auto c) { return c == '0'; })) {
        tmp = "0";
      }
      reverse(tmp.begin(), tmp.end());
      ans = add(ans, tmp);
    }
    return ans;
  }

 private:
  string add(const string& num1, const string& num2) {
    string ans;
    int i = num1.size() - 1, j = num2.size() - 1;
    int flag = 0;
    while (i >= 0 || j >= 0) {
      int c1 = i >= 0 ? num1[i] - '0' : 0;
      int c2 = j >= 0 ? num2[j] - '0' : 0;
      int sum = c1 + c2 + flag;
      flag = sum / 10;
      ans.push_back(sum % 10 + '0');
      i--;
      j--;
    }
    if (flag > 0) {
      ans.push_back(flag + '0');
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};

int main(int argc, char const* argv[]) {
  string num1{"125"};
  string num2{"81"};
  cout << (new Solution)->multiply(num1, num2) << endl;
  return 0;
}
