#include <iostream>
#include <string>
using namespace std;

class Solution {
 public:
  int compareVersion(string version1, string version2) {
    int n = version1.size(), m = version2.size();
    int i = 0, j = 0;
    while (i < n || j < m) {
      long long num1 = 0, num2 = 0;
      while (i < n && version1[i] != '.') {
        num1 = num1 * 10 + (version1[i] - '0');
        i++;
      }
      while (j < m && version2[j] != '.') {
        num2 = num2 * 10 + (version2[j] - '0');
        j++;
      }

      if (num1 < num2) return -1;
      if (num1 > num2) return 1;

      i++;
      j++;
    }

    return 0;
  }
};

int main(int argc, char const *argv[]) {
  cout << (new Solution)->compareVersion("1.01", "1.001") << endl;
  return 0;
}
