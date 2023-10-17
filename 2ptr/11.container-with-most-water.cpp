#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxArea(vector<int>& height) {
    if (height.empty()) {
      return 0;
    }

    int l = 0, r = height.size() - 1;
    int res = 0;
    while (l < r) {
      res = max(res, (r - l) * min(height[l], height[r]));
      if (height[l] < height[r]) {
        l++;
      } else {
        r--;
      }
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  cout << (new Solution)->maxArea(height) << endl;
  return 0;
}
