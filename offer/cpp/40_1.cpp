#include <algorithm>
// 排序+取前k个数
// 时间复杂度O(NlogN)+O(N)
// 空间复杂度O(K)
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> getLeastNumbers(vector<int> &arr, int k) {
    vector<int> res;
    sort(arr.begin(), arr.end());
    for (int i = 0; k > 0 && i < arr.size(); i++) {
      res.push_back(arr[i]);
      k--;
    }

    return res;
  }
};

int main(int argc, const char *argv[]) {
  vector<int> arr{0, 0, 1, 2, 4, 2, 2, 3, 1, 4};
  auto res = (new Solution())->getLeastNumbers(arr, 8);
  for (auto e : res) {
    cout << e << endl;
  }
  return 0;
}