#include <climits>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int i = m - 1, j = n - 1, cur = m + n - 1;
    while (i >= 0 || j >= 0) {
      int num1 = i >= 0 ? nums1[i] : INT_MIN;
      int num2 = j >= 0 ? nums2[j] : INT_MIN;
      if (num1 > num2) {
        nums1[cur--] = num1;
        i--;
      } else {
        nums1[cur--] = num2;
        j--;
      }
    }
  }
};

int main(int argc, char const *argv[]) {
  vector<int> nums1{1, 2, 3, 0, 0, 0};
  vector<int> nums2{2, 5, 6};
  (new Solution)->merge(nums1, 3, nums2, 3);
  auto pv = [](const auto res) {
    for (auto &&i : res) cout << i << " ";
    cout << '\n';
  };
  pv(nums1);
  return 0;
}
