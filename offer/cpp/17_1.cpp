#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> printNumbers(int n) {
    int max = pow(10, n);
    vector<int> seq(max - 1, 0);
    for (int i = 0; i < max - 1; i++) {
      seq[i] = i + 1;
    }
    return seq;
  }
};

int main(int argc, const char *argv[]) {
  auto res = (new Solution())->printNumbers(3);
  for (auto e : res) {
    cout << e << endl;
  }
  return 0;
}