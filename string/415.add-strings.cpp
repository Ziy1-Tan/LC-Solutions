#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
class Solution {
 public:
  string addStrings(string num1, string num2) {
    string ans;
    int i = num1.size() - 1, j = num2.size() - 1;
    int flag = 0;
    while (i >= 0 || j >= 0 || flag != 0) {
      int c1 = i >= 0 ? num1[i] - '0' : 0;
      int c2 = j >= 0 ? num2[j] - '0' : 0;
      int sum = c1 + c2 + flag;
      flag = sum / 10;
      ans.push_back(sum % 10 + '0');
      i--;
      j--;
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};

int main(int argc, char const *argv[]) {
  cout << (new Solution)->addStrings("10", "0") << endl;
  return 0;
}
