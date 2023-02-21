#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxArea(vector<int> &height) {
    int l = 0, r = height.size() - 1;
    int ans = 0;
    while (l < r) {
      ans = height[l] < height[r]
                ? max(ans, (r - l) * min(height[l++], height[r]))
                : max(ans, (r - l) * min(height[l], height[r--]));
    }
    return ans;
  }
};

int main(int argc, char const *argv[]) {
  vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  cout << (new Solution)->maxArea(height) << endl;
  return 0;
}
